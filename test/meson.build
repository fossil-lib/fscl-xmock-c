if get_option('with_test').enabled()
    test_deps = [
        dependency('tscl-xtest-c')
    ]

    test_source = files(
        'xtest_stub.c',     'xtest_inject.c',
        'xtest_spy.c',      'xtest_fake.c',
        'xtest_behavior.c', 'xtest_output.c',
        'xunit_runner.c')

    test('Execute project Xunit tests', 
        executable('xrunner', test_source,
        dependencies : [test_deps, tscl_xmock_c_dep]))
endif
