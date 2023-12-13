if get_option('with_demo').enabled()
    demo_apps = [
        'stub', 'inject', 'spy', 'fake', 'behavior', 'output']

    foreach iter : demo_apps
        executable('demo_' + iter, 'demo_' + iter + '.c', dependencies : [tscl_xmock_c_dep])
    endforeach
endif
