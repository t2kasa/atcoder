import os
from copy import deepcopy
from glob import glob

_common_lines = ['cmake_minimum_required(VERSION 3.10)',
                 'set(CMAKE_CXX_STANDARD 14)']
_cmake_lists_file_name = 'CMakeLists.txt'


def make_cmake_lists(parent_dir):
    lines = deepcopy(_common_lines)

    # project name
    project_name = os.path.basename(parent_dir)
    lines += ['project({})'.format(project_name)]

    # sub directories
    cpp_dirs = obtain_cpp_contain_dirs(parent_dir)
    lines += ['add_subdirectory({})'.format(os.path.relpath(d, parent_dir))
              for d in cpp_dirs]

    # cpp files
    cpp_files = obtain_cpp_files(parent_dir)
    lines += ['add_executable({} {})'.format(
        os.path.splitext(os.path.basename(f))[0],
        os.path.relpath(f, parent_dir)) for f in cpp_files]

    # add a line separator
    lines = ['{}\n'.format(line) for line in lines]

    # make texts in CmakeLists.txt
    cmake_lists_file = os.path.join(os.path.abspath(parent_dir),
                                    _cmake_lists_file_name)
    with open(cmake_lists_file, 'w') as f:
        f.writelines(lines)

    # call recursively
    for d in cpp_dirs:
        make_cmake_lists(d)


def obtain_cpp_contain_dirs(parent_dir):
    cpp_dirs = [d for d in glob(os.path.join(parent_dir, '*')) if
                any(glob(os.path.join(d, '*.cpp')))]
    return cpp_dirs


def obtain_cpp_files(parent_dir):
    return [f for f in glob(os.path.join(parent_dir, '*.cpp'))]


def main():
    root = os.path.dirname(os.path.abspath(__file__))
    make_cmake_lists(root)


if __name__ == '__main__':
    main()
