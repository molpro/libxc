
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_gga_xc_pbe_sol0_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_pbe_sol0", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.255834808953203e+00, -3.192811007911373e+00, -3.104512696144700e+00, -2.982227921054790e+00, -2.815671234475168e+00, -2.594174353126288e+00, -2.309543309946405e+00, -1.961324894205572e+00, -1.564300303130308e+00, -1.153663844993337e+00, -7.721676821912741e-01, -5.359633362656695e-01, -4.733231667055001e-01, -3.863796108215463e-01, -2.727486719335337e-01, -1.661109990981948e-01, -8.657089483812663e-02, -3.113549294043742e-02, -6.574222771036267e-03, -7.276171974071947e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_gga_xc_pbe_sol0_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_pbe_sol0", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.224048571943868e+00, -4.137911916321050e+00, -4.017100467175626e+00, -3.849512449294800e+00, -3.620671246735579e+00, -3.315128810600806e+00, -2.919991269660396e+00, -2.431764801982107e+00, -1.868286196486054e+00, -1.291804127757378e+00, -8.437042225388057e-01, -6.996348570910867e-01, -6.223513746622178e-01, -5.045651666340132e-01, -3.435155938003254e-01, -1.860670488579321e-01, -9.357849800948385e-02, -3.988157901919304e-02, -8.748217481332530e-03, -9.701313821932082e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_pbe_sol0_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_pbe_sol0", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.012738019259082e-06, -1.106229715766399e-06, -1.255317853375411e-06, -1.503908234129530e-06, -1.945579957733860e-06, -2.804094248397153e-06, -4.696948787356437e-06, -9.660054182737384e-06, -2.600337125514091e-05, -9.619389056318397e-05, -4.798746659207158e-04, -1.751061895039741e-04, 1.610504888678938e-03, 2.543103517364982e-05, -1.251357453945542e-02, -1.763737433748446e-01, -1.467129199844314e+00, -3.674180120752860e+00, -4.740648542854376e+00, -5.260713058692050e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_pbe_sol0_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_pbe_sol0", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-8.874505666904221e-03, -9.284506645865404e-03, -9.908593608675348e-03, -1.088254200698068e-02, -1.245817264813526e-02, -1.514286296385809e-02, -2.006935823192081e-02, -3.008653111724909e-02, -5.313531966766330e-02, -1.099505450320181e-01, -2.632579563584762e-01, -4.054198355439636e-01, -4.739613087602704e-01, -8.501005837408192e-01, -2.450713373722696e+00, -8.850792728838204e+00, 1.162566332133019e+01, -2.261875970879475e+02, -9.967030111237947e+03, -8.373337887734170e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_pbe_sol0_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_pbe_sol0", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.324023503892190e-08, 1.521156866171556e-08, 1.856125800777847e-08, 2.468056341565682e-08, 3.707731838728941e-08, 6.616479367394169e-08, 1.500705876055985e-07, 4.714181767380700e-07, 2.241232562095040e-06, 1.646851333129605e-05, 2.675770482655391e-04, 4.905829834012004e-03, 3.699927314507688e-03, 5.297680420374878e-02, 9.197262305155487e-01, 2.317748510786949e+01, -2.860164579860922e+03, -4.202030108439187e+05, -6.608086346749847e+07, -5.449966581636881e+10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_pbe_sol0_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_pbe_sol0", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-7.143898354507597e-14, -8.627825602425358e-14, -1.130634003044798e-13, -1.663963104782634e-13, -2.884422571921268e-13, -6.277386093196260e-13, -1.855018610844786e-12, -7.941907816306908e-12, -3.911082694726196e-11, 1.682141461558541e-09, 2.865996122479966e-07, -4.215126004497236e-04, -3.833571257490115e-03, -2.290405659987218e-02, -7.380508014912578e-01, -3.230753614144146e+01, 3.245101510148490e+05, 1.288302148744555e+09, 2.401553485560142e+13, 1.536446745212245e+19]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
