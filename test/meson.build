if get_option('with_test').enabled()
    test_deps = [
        dependency('trilo-xtest-c')
    ]

    test_source = files(
        'xtest_stub.c',
        'xtest_inject.c',
        'xtest_spy.c',
        'xtest_fake.c',
        'xtest_behavior.c',
        'xtest_cases.c',
        'xunit_runner.c')

    test('Execute project Xunit tests', 
        executable('xrunner', test_source,
        dependencies : [test_deps, trilo_xmock_c_dep]))
endif
