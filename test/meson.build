if get_option('with_test').enabled()
    test_deps = [
        dependency('trilo-xtest-c'),
        dependency('trilo-xmock-c')
    ]

    test_source = files('xtest_cases.c', 'xunit_runner.c')

    test('Execute project Xunit tests', 
        executable('xrunner', test_source,
        dependencies : [test_deps, trilo_c_dep]))
endif