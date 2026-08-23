
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_c_wl_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_wl", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.428548119401802e-02, -6.321046710969928e-02, -6.167676316154440e-02, -5.949669937886492e-02, -5.641491503992450e-02, -5.209574671530910e-02, -4.612870135934907e-02, -3.810098702044437e-02, -2.789459468630487e-02, -1.677263578033714e-02, -1.208320812591290e-02, -4.771111034916766e-02, -6.752683113748023e-02, -4.115841039419511e-02, -2.073383029215418e-02, -3.211251188815675e-03, 1.069330955248472e-02, 1.911893985861384e-02, 2.255430944511779e-02, 2.335561468149985e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_c_wl_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_wl", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.374177348826714e-01, -1.360150903587744e-01, -1.339914409746382e-01, -1.310693958848617e-01, -1.268475321404125e-01, -1.207508338281765e-01, -1.119831733202157e-01, -9.955617742106657e-02, -8.270780577933284e-02, -6.299088290542001e-02, -5.403434730323663e-02, -1.108162915628259e-01, -1.345596751670590e-01, -9.996821743993189e-02, -6.700153586302780e-02, -3.474942184568736e-02, -6.749419754911135e-03, 1.122148127889327e-02, 1.877103017910417e-02, 2.056607280617522e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_wl_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_wl", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([7.819832650128462e-07, 8.292599822579205e-07, 9.020270026906909e-07, 1.017317987993713e-06, 1.207619127035974e-06, 1.540373671673263e-06, 2.171265339428937e-06, 3.512689544558605e-06, 6.897826621080544e-06, 1.855936617900543e-05, 1.114794277292394e-04, 4.983947598270391e-03, 2.414629478122773e-02, 2.143880252547073e-02, 4.306539675373876e-02, 1.683718723187796e-01, 1.205995466068459e+00, 1.930804710682052e+01, 1.255839539992476e+03, 7.760184549959702e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_wl_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_wl", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.244214377009783e-04, -5.602396347435200e-04, -6.156882683402155e-04, -7.042608346782877e-04, -8.521455218162855e-04, -1.114824645141304e-03, -1.623073151108780e-03, -2.727725968416494e-03, -5.530349474722859e-03, -1.422238317455812e-02, -4.848032919308333e-02, -1.425357496391332e-01, -1.859299571197023e-01, -3.981106480313357e-01, -1.153280677852366e+00, -5.006905170273272e+00, -3.496009240408112e+01, -4.873032171690530e+02, -2.493304090755330e+04, -1.293394096014369e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_wl_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_wl", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([5.587400004880378e-09, 6.358542683608689e-09, 7.652818558373295e-09, 9.975422489740021e-09, 1.456082948089801e-08, 2.492939029481583e-08, 5.334091611860112e-08, 1.554259007407674e-07, 6.938360143359369e-07, 5.693319890350818e-06, 1.282934419092325e-04, 1.107056496021238e-02, 6.469039278493503e-02, 1.421888644467373e-01, 1.055839499275725e+00, 2.630561977326350e+01, 2.374628654835777e+03, 1.166469846286957e+06, 8.145197071443017e+09, 3.586839838305855e+15]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_wl_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_wl", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.377233577033653e-13, -1.660712881039993e-13, -2.172628566704783e-13, -3.193877830940284e-13, -5.544560713761736e-13, -1.218809294554276e-12, -3.738590911011385e-12, -1.831187388817002e-11, -1.736777314681146e-10, -4.392434113819791e-09, -6.478032010826719e-07, -1.942448989130942e-03, -5.926345879182161e-02, -1.133680194016675e-01, -1.980636527228309e+00, -2.674050239973353e+02, -2.988498605308434e+05, -4.957630934747405e+09, -4.423000847259086e+15, -1.571187205673683e+24]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
