code = files(
    'spy.c', 'fake.c', 'stub.c',
    'behavior.c', 'inject.c', 'output.c')

lib = static_library('fscl-xmock-c',
    code,
    include_directories: dir)

fscl_xmock_c_dep = declare_dependency(
    link_with: lib,
    include_directories: dir)
