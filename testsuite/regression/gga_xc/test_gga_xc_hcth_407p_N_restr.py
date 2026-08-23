
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_xc_hcth_407p_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_hcth_407p", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.523238894905778e+00, -4.431919134213337e+00, -4.304059700336706e+00, -4.127170845866965e+00, -3.886661868558674e+00, -3.567800702976747e+00, -3.160416745910609e+00, -2.668044120882549e+00, -2.123341655256267e+00, -1.600295067803342e+00, -1.105852361048430e+00, -7.173627854774534e-01, -6.296465848413277e-01, -5.138897841505792e-01, -3.788991390801421e-01, -2.654845693694887e-01, -1.120908212395613e-01, -1.881755888754654e-04, 5.432228023104196e-03, 8.477684898359804e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_xc_hcth_407p_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_hcth_407p", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.091315516812448e+00, -5.964757071884455e+00, -5.786949600879646e+00, -5.539711772181174e+00, -5.200992354398998e+00, -4.746588327281184e+00, -4.154273314451478e+00, -3.409434053364606e+00, -2.509205448471484e+00, -1.522937735798991e+00, -9.054221657823835e-01, -9.238256124256294e-01, -8.483017918807547e-01, -6.412013552569623e-01, -3.969292305433819e-01, -2.222878685955216e-01, -2.272543446335365e-01, -2.047068219165272e-02, 6.421460429550432e-03, 1.114279117943628e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_xc_hcth_407p_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_hcth_407p", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([8.535068678186922e-07, 8.534425204646994e-07, 8.417548735709890e-07, 7.955289543330910e-07, 6.485356862894622e-07, 1.923504791919113e-07, -1.329016352464159e-06, -7.318265702990584e-06, -3.792551494139868e-05, -2.374373412665178e-04, -1.469743511207832e-03, -1.807947216069859e-03, 6.510378684166988e-03, -1.297355947580253e-02, -9.290526171078077e-02, -6.782308658812645e-01, 4.705693136277456e+00, 3.346455064677725e+01, 6.091209111956672e+01, 7.832284667889787e+01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_xc_hcth_407p_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_hcth_407p", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.297991419528579e-02, -1.364008269321080e-02, -1.464810030440671e-02, -1.622927451557126e-02, -1.881303113093775e-02, -2.332241922183091e-02, -3.214705195453776e-02, -5.327447537588621e-02, -1.199357297055872e-01, -3.428704816519011e-01, -7.931295506357646e-01, -7.371008133903559e-01, -8.678389470510154e-01, -1.534618220207694e+00, -4.576961430802495e+00, 1.134254711691963e+01, -5.441986115072999e+01, -2.026967189828609e+03, 1.247391148712883e+03, 8.944851279539544e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_xc_hcth_407p_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_hcth_407p", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.873642764295969e-08, 2.219969194103129e-08, 2.817223870792672e-08, 3.930937010876324e-08, 6.258494747559841e-08, 1.203487350704867e-07, 3.079649895042689e-07, 1.229389113095659e-06, 8.903795707050259e-06, 1.046597256515003e-04, 1.653248098659717e-03, 1.989251060130596e-02, 7.737961447936181e-02, 2.042495566993983e-01, 2.546964048489183e+00, -8.471319169244242e+01, -6.697107047094860e+02, 3.661869174246375e+06, 8.408161058915504e+08, 8.092908725764342e+11]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_xc_hcth_407p_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_hcth_407p", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.675878459035302e-13, -3.283404838472547e-13, -4.390732447289509e-13, -6.625805795835535e-13, -1.185376975035685e-12, -2.707336319661123e-12, -8.941206510063525e-12, -5.313926536894558e-11, -7.285021648382529e-10, -2.039806733732686e-08, -1.176774931983678e-06, -1.213466349536867e-03, -3.705237088194014e-02, -4.108794866359058e-02, -5.938606579305604e-01, 8.307182960670553e+02, -4.994779777307793e+05, -1.163354986343341e+10, -3.087385708235084e+14, -2.287548458368708e+20]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
