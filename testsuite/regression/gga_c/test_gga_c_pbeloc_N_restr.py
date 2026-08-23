
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_c_pbeloc_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_pbeloc", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-7.668228712336131e-02, -7.560176138806077e-02, -7.404111647964466e-02, -7.178147570883517e-02, -6.849610290353096e-02, -6.368526119260989e-02, -5.655769992262303e-02, -4.583589026355456e-02, -2.988070447993097e-02, -1.126331088354743e-02, -4.503503199738384e-03, -4.579194656486899e-02, -5.564759684198277e-02, -3.730827273416130e-02, -1.288710725104904e-02, -1.179922549726845e-03, -1.751587683666661e-05, -2.508346350521414e-08, -1.314569265672418e-12, -5.777086046815288e-19]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_c_pbeloc_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_pbeloc", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.429067848929483e-01, -1.423035672633190e-01, -1.414422358481127e-01, -1.402167666720240e-01, -1.384818405325817e-01, -1.360368060941672e-01, -1.325578058978735e-01, -1.270882581992033e-01, -1.141173348457031e-01, -7.126759973834904e-02, -3.689817807938615e-02, -1.030557819047044e-01, -8.433820816470296e-02, -9.577047333504443e-02, -6.961708313067286e-02, -1.034792258936166e-02, -1.810746276234542e-04, -2.734249596407514e-07, -1.466704345718240e-11, -6.514531418493533e-18]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_pbeloc_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_pbeloc", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([6.846476049178750e-07, 7.350726599570995e-07, 8.141997941826031e-07, 9.431959691553535e-07, 1.165353108014908e-06, 1.579284311158180e-06, 2.441525824879241e-06, 4.525704396287428e-06, 1.029719054749641e-05, 2.327552463220330e-05, 8.341280743729534e-05, 4.291995129128399e-03, 8.564271474265004e-03, 2.071337780018812e-02, 5.452847979700170e-02, 5.194401592790841e-02, 1.173862653639972e-02, 5.893332107677807e-04, 3.798651030972084e-06, 1.302147905708946e-09]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_pbeloc_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_pbeloc", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.213815160593304e-04, -1.306010356793618e-04, -1.450439465099205e-04, -1.686087707148796e-04, -2.096260603873609e-04, -2.895108822947892e-04, -4.832558533761036e-04, -1.210429546523925e-03, -6.236333358354448e-03, -4.115882966067111e-02, -1.327433022719756e-01, 5.943299311171182e-02, 5.770842986491913e-02, 1.409773424896446e-01, -2.397075924890821e+00, -6.216502184154987e+00, -1.688805525876316e+00, -8.370973091244577e-02, -5.210277562972935e-04, -1.733703352594988e-07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_pbeloc_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_pbeloc", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([9.327570002921148e-10, 1.083582100076807e-09, 1.342810053533594e-09, 1.825351657766071e-09, 2.836779801021949e-09, 5.384988808742461e-09, 1.411586006470098e-08, 6.587146613686717e-08, 7.690803897470602e-07, 1.603409229542740e-05, 3.419890876397502e-04, -6.050297194786686e-03, -3.113301676273690e-02, -7.256442712414372e-02, 2.230013639521308e+00, 3.510884689311198e+01, 1.211108724685548e+02, 1.986188333839137e+02, 1.482355754898840e+02, 3.802814464736032e+01]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))


def test_gga_c_pbeloc_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_pbeloc", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-7.560436694535055e-14, -9.225823174624319e-14, -1.228248980116722e-13, -1.853089422345811e-13, -3.346228281070393e-13, -7.826709539079752e-13, -2.665760456832255e-12, -1.591418194984014e-11, -2.261819029043798e-10, -8.953234991219916e-09, -1.117142043490837e-06, -3.796195380345145e-04, 3.748997947064455e-04, -2.772913651571952e-02, -3.352180617515881e+00, -2.366827415990828e+02, -9.985465389977844e+03, -5.377272614859714e+05, -4.804010609169461e+07, -9.502652042657232e+09]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))
