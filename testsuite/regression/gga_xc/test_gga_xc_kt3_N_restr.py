
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_xc_kt3_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_kt3", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.786016247047963e+00, -4.697973932317659e+00, -4.574863835968793e+00, -4.404882048406522e+00, -4.174476685440066e+00, -3.870540348692990e+00, -3.485556782999531e+00, -3.027375172326394e+00, -2.532776004236103e+00, -2.053319450756893e+00, -1.424102617197221e+00, -7.583538371429089e-01, -6.451974299931422e-01, -5.308506231727804e-01, -3.731374995049760e-01, -2.315597495268782e-01, -1.217957440087096e-01, -5.088808671708955e-02, -1.092687001142076e-02, -1.210618420346011e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_xc_kt3_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_kt3", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.840468590467431e+00, -5.711366470796881e+00, -5.529902142494059e+00, -5.277328360865337e+00, -4.930567000205958e+00, -4.463371254506143e+00, -3.849567157578341e+00, -3.069541872143538e+00, -2.127904182887614e+00, -1.149253841049619e+00, -7.026222316561996e-01, -9.197100275980477e-01, -8.331545810952747e-01, -6.624039985497723e-01, -4.300399255237959e-01, -2.351637516070058e-01, -1.617693308512266e-01, -6.558748037493545e-02, -1.453997028218291e-02, -1.614061850564774e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_xc_kt3_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_kt3", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.629094788950628e-06, -6.130976852772024e-06, -6.932259838842409e-06, -8.271523156457238e-06, -1.066259295808730e-05, -1.535649302813764e-05, -2.591414416862026e-05, -5.470187368024567e-05, -1.564942092986509e-04, -6.414946082098215e-04, -3.314982469178211e-03, -7.788026118448016e-03, -9.480344686296873e-03, -1.933728373674724e-02, -6.930944413274816e-02, -3.917657179131326e-01, 7.132903011814649e-01, -9.140430015052932e-01, -6.634035065576175e+00, -7.328560470614888e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_xc_kt3_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_kt3", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.545355172657534e-02, -1.630367129245952e-02, -1.762063192025878e-02, -1.973068479751199e-02, -2.328333243040911e-02, -2.971982073905806e-02, -4.270773525479912e-02, -7.321297349735684e-02, -1.589745907605621e-01, -4.190779493565046e-01, -8.993390110036303e-01, -6.644473068496326e-01, -7.024203650589177e-01, -1.321853188356511e+00, -3.784962845101095e+00, 6.867623515687539e-01, 9.619030323535416e+01, -4.155614104985809e+02, -1.660140812331363e+04, -1.392924834297720e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_xc_kt3_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_kt3", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([5.030074025256483e-08, 5.845068487894161e-08, 7.252681267556026e-08, 9.886893655935986e-08, 1.541874464372659e-07, 2.912066143472715e-07, 7.202884271337399e-07, 2.581360108146746e-06, 1.492700555987997e-05, 1.464040772791652e-04, 2.248225968219657e-03, 1.816351217433406e-02, 2.636460204268055e-02, 1.417318700805622e-01, 1.680249122358510e+00, -3.998131297166999e+01, -1.119500984348192e+04, -5.057993818167659e+05, -9.245355555622995e+07, -7.571890045624608e+10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_xc_kt3_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_kt3", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-9.112864424162464e-14, -1.147940825172923e-13, -1.597908442539584e-13, -2.563712601701116e-13, -5.027433713320456e-13, -1.304777003178414e-12, -4.963631797464857e-12, -3.094533866756083e-11, -3.266183960513279e-10, -1.866957342134051e-09, 6.484455114310982e-07, -4.982355947045055e-04, -3.616525393174569e-03, -2.980097336920892e-02, -6.385613095254273e-01, 4.459883872613557e+02, 8.263643896240087e+05, 1.965547248667143e+09, 3.357862457430230e+13, 2.134629051005430e+19]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
