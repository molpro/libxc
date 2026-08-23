
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_x_mb88_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_mb88", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.209212679167257e+00, -4.125929105369543e+00, -4.009258172812462e+00, -3.847703170004482e+00, -3.627702108692872e+00, -3.335207635827282e+00, -2.959463379689594e+00, -2.499958043194502e+00, -1.976508830954813e+00, -1.438177653234589e+00, -9.514421493946382e-01, -6.411567032197991e-01, -5.536383977251383e-01, -4.517470773291121e-01, -3.178136734750873e-01, -1.957353861033750e-01, -1.167188893188555e-01, -7.860976329263240e-02, -5.645358482881407e-02, -4.044007800577053e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_x_mb88_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_mb88", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.492478686178182e+00, -5.379427053496681e+00, -5.220942504131630e+00, -5.001252221060532e+00, -4.701585726121016e+00, -4.302118724182562e+00, -3.786731532772883e+00, -3.151936537911140e+00, -2.420985174438216e+00, -1.666760514148465e+00, -1.063631887350008e+00, -8.251193050509538e-01, -7.266030418029650e-01, -5.761982791170723e-01, -3.800406161234249e-01, -1.966653744406559e-01, -7.236025063911626e-02, -2.403133669006351e-02, -1.268423988339454e-02, -6.417129984398323e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_mb88_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_mb88", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.285483421014319e-06, -1.392253915026697e-06, -1.561242549079051e-06, -1.840083957532436e-06, -2.328475627398526e-06, -3.260027647129019e-06, -5.266221142785633e-06, -1.039601229605687e-05, -2.704666510889481e-05, -1.009274709814636e-04, -5.458942290777687e-04, -2.387739285639942e-03, -4.302656716846358e-03, -9.708375626578261e-03, -4.118711983835539e-02, -3.443933443704216e-01, -5.644468698114657e+00, -1.820319367416378e+02, -1.704044473172783e+04, -1.004378827619259e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_mb88_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_mb88", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.103173578756331e-02, -1.151667124873467e-02, -1.225225291499092e-02, -1.339445267888108e-02, -1.522907199176452e-02, -1.832395301875918e-02, -2.393042529102745e-02, -3.519322279539396e-02, -6.137277488654205e-02, -1.336811384902768e-01, -3.312614119779494e-01, -4.998780009649816e-01, -6.237490672054327e-01, -1.038012426394670e+00, -2.533208226783313e+00, -9.590980404633086e+00, -4.660268699067684e+01, 1.339459523748969e+02, 2.524398116906601e+04, 1.076532001568097e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_mb88_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_mb88", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([8.676193916264821e-09, 9.964627537821403e-09, 1.215557697642449e-08, 1.616391140824683e-08, 2.430818353482170e-08, 4.353740999884405e-08, 9.978650965493077e-08, 3.226430471051883e-07, 1.668964814098631e-06, 1.586675239373080e-05, 2.945193572320132e-04, 4.476571719376540e-03, 1.289220414160277e-02, 5.156409506168762e-02, 6.053219875015212e-01, 2.120337849983868e+01, 1.494191893880146e+03, -8.626677302238141e+05, -1.090358019071503e+10, -3.447602779169744e+15]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_mb88_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_mb88", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([9.597461197248098e-15, 1.206243861601673e-14, 1.674909350076053e-14, 2.682349017108220e-14, 5.267045713462673e-14, 1.382493247435472e-13, 5.474349551104559e-13, 3.864897325029392e-12, 6.087973851793242e-11, 2.801601199209740e-09, 4.222392043913089e-07, 5.327207587282488e-05, 3.938814048274802e-04, 3.358562507572990e-03, 2.019656092340167e-01, 9.768040508297835e+01, 4.182144382261366e+05, 1.893675504168614e+10, 2.462738502414722e+16, 8.062861221057308e+24]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
