code = files('module.c')

lib = library('trilo-c',
    code,
    include_directories: dir,
    install: true)

trilo_c_dep = declare_dependency(
    link_with: lib,
    include_directories: dir)