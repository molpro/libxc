
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_gga_xc_pbe_mol0_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_pbe_mol0", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.311576330176826e+00, -3.249621541883061e+00, -3.162873194451636e+00, -3.042842810766685e+00, -2.879577432505379e+00, -2.662899661480605e+00, -2.385296749593447e+00, -2.046989688984922e+00, -1.661879617789905e+00, -1.255926103485095e+00, -8.471135084410232e-01, -5.436838180998285e-01, -4.747265974834845e-01, -3.924359419665798e-01, -2.850480647688032e-01, -1.809915649168416e-01, -9.231901379200813e-02, -3.148579126023547e-02, -6.577837746061218e-03, -7.276223518622399e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_gga_xc_pbe_mol0_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_pbe_mol0", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.134409405842887e+00, -4.047369718440738e+00, -3.925306579049732e+00, -3.756024241019132e+00, -3.524993796981063e+00, -3.216913856790860e+00, -2.819743386685456e+00, -2.333174095142945e+00, -1.785089307826069e+00, -1.255605700398746e+00, -8.342732085238574e-01, -6.814234265597001e-01, -6.173943835633714e-01, -4.898368215102886e-01, -3.246338879976035e-01, -1.876377622555801e-01, -1.080546524180427e-01, -4.120428728886187e-02, -8.762630620202045e-03, -9.701519989275434e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_pbe_mol0_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_pbe_mol0", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.815301391858581e-06, -3.053209480698714e-06, -3.429360084710801e-06, -4.048778705145106e-06, -5.129311753961215e-06, -7.173066586924628e-06, -1.149543895354242e-05, -2.210573400444075e-05, -5.342652132044440e-05, -1.669529127198458e-04, -7.783991972083829e-04, -2.597692581601709e-03, -1.131107647124067e-03, -9.000954660704875e-03, -4.768257761161372e-02, -2.810005600059420e-01, -1.014562631326803e+00, -1.749048293877953e+00, -2.128957350229577e+00, -2.354726448363518e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_pbe_mol0_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_pbe_mol0", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-9.742365993639885e-03, -1.020242211351680e-02, -1.090155857899835e-02, -1.198917202673566e-02, -1.373727990965246e-02, -1.667400043267029e-02, -2.188781753864939e-02, -3.163045204149928e-02, -4.916395698563360e-02, -6.648929799362491e-02, -1.083420707003859e-01, -4.728689314730070e-01, -5.166234867270389e-01, -1.009146530201508e+00, -2.498678454493157e+00, -2.042416638974202e+00, 8.127186384581638e+00, -3.339807852904600e+02, -1.011733804975038e+04, -8.374939706886503e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_pbe_mol0_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_pbe_mol0", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.428730493625901e-08, 2.768273933136682e-08, 3.338119177638263e-08, 4.359593876312792e-08, 6.368110919949693e-08, 1.085431888671711e-07, 2.270782255528812e-07, 6.069105845942756e-07, 1.907724156452173e-06, -6.876641580257837e-07, -1.512062007833777e-04, 1.132012931037182e-02, 2.214188214694891e-02, 1.233195924437364e-01, 1.042414856679890e+00, -1.520304253461032e+01, -3.007672273948397e+03, -2.087642467028819e+05, -2.974178973509045e+07, -2.439520594932595e+10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_pbe_mol0_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_pbe_mol0", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.829567012283058e-14, -5.543096213683201e-14, -6.687444967744471e-14, -8.518301540121147e-14, -1.103291306603544e-13, -9.859405761891970e-14, 5.283204422232200e-13, 1.097909600420376e-11, 2.793286037360737e-10, 1.512988753143236e-08, 2.079666648896007e-06, -5.578617023239451e-04, -8.060939535861953e-03, -3.038539314651741e-02, -2.166645196811137e-01, 2.428454729717666e+02, 2.956339487507984e+05, 6.332179717205975e+08, 1.080318431432332e+13, 6.877404099529976e+18]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
