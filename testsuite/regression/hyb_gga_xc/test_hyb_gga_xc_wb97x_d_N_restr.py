
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_gga_xc_wb97x_d_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_wb97x_d", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.343522178648817e+00, -3.278571721381234e+00, -3.187627365278032e+00, -3.061808609840396e+00, -2.890757255761107e+00, -2.664031801690590e+00, -2.374248357255599e+00, -2.022051534182408e+00, -1.620078725554042e+00, -1.192342868345690e+00, -7.747135774623874e-01, -4.750577108443095e-01, -4.062584881732581e-01, -3.201973259269549e-01, -2.135059485864890e-01, -1.042078920955107e-01, -3.456106116774615e-02, 1.053728131654211e-02, 4.168458130237209e-03, 4.976784055350053e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_gga_xc_wb97x_d_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_wb97x_d", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.257175762228539e+00, -4.166115153210449e+00, -4.037927596755654e+00, -3.859272835203677e+00, -3.614048904138997e+00, -3.285465592805455e+00, -2.862420165522881e+00, -2.353847074252240e+00, -1.806510260800702e+00, -1.260009047168921e+00, -7.789334482098996e-01, -6.144394131804815e-01, -5.614867340110107e-01, -4.098209069597398e-01, -2.643015038565389e-01, -1.070781135879815e-01, -1.926358458126093e-02, 7.453481859058276e-03, 5.379320749026389e-03, 6.625727751846649e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_wb97x_d_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_wb97x_d", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.232156421718468e-06, -2.433012372382593e-06, -2.757786266037223e-06, -3.308457485790400e-06, -4.303324642991583e-06, -6.252154868054943e-06, -1.045231345564971e-05, -2.045623947328730e-05, -4.676058622888708e-05, -1.412865856937030e-04, -7.416419994420346e-04, -2.898233726073207e-03, 1.934814401831835e-03, -1.290942784991158e-02, -3.698558931096090e-02, -2.848557062597432e-01, -3.603814455579935e+00, 5.880859205862702e+00, 1.442760036350182e+01, 1.817527116551878e+01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_wb97x_d_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_wb97x_d", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.003370451672868e-02, -1.062001971427503e-02, -1.150855988248627e-02, -1.287641536175825e-02, -1.501355930757806e-02, -1.836884768073839e-02, -2.348242031515320e-02, -3.029995896697017e-02, -3.771743761089633e-02, -1.190645013250048e-01, -5.548645744498149e-01, -6.274243003337399e-01, -3.883270827626793e-01, -1.248952694705487e+00, -5.675949869035918e-01, -2.907817083609714e+01, 5.081768637942243e+01, -3.835447540028252e+02, 4.808440509689475e+03, 5.665918216112474e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_wb97x_d_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_wb97x_d", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.336511536691365e-08, 2.794535364986859e-08, 3.571336132374578e-08, 4.968118186397023e-08, 7.663273810640867e-08, 1.325805160001862e-07, 2.529488639619258e-07, 4.616174312300072e-07, 1.805516253957108e-07, 1.924616154117223e-05, 1.051469276706424e-03, 2.259634020058517e-02, -3.128390103576402e-02, 2.049905488543639e-01, -8.611332815133024e-01, 1.423333884862026e+02, -3.394536621648238e+03, 6.129706539323819e+05, 1.993420694845670e+08, 1.879045795557794e+11]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_wb97x_d_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_wb97x_d", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-8.345998753277238e-14, -1.125632536343183e-13, -1.657538205386116e-13, -2.700579217389789e-13, -4.870914716469719e-13, -9.133325281336941e-13, -9.025927074063452e-13, 1.687809085971632e-11, 4.373616272352070e-10, 4.550090304759089e-09, -1.279215929537341e-06, -1.390872738359959e-03, 6.907825592884313e-03, -4.996733588948989e-02, 1.380171828327196e+00, -6.694327826850182e+02, 3.275747217088662e+05, -2.120347950745052e+09, -7.317728270308692e+13, -5.308428964005269e+19]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
