
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_k_revapbe_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_revapbe", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([9.461643399868805e+01, 9.095756201700657e+01, 8.595425306725365e+01, 7.926184902278884e+01, 7.058835659721689e+01, 5.984205925687750e+01, 4.735034018877167e+01, 3.407358792071832e+01, 2.160260981215849e+01, 1.164843618558824e+01, 5.127870950174329e+00, 2.214683132533920e+00, 1.630668302796022e+00, 1.105350304358007e+00, 5.637922380981107e-01, 2.153964140038633e-01, 5.453013063587358e-02, 6.386204792742779e-03, 2.792812508576145e-04, 3.417674739031354e-06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_k_revapbe_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_revapbe", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.489186576886553e+02, 1.428583800902153e+02, 1.345756202046379e+02, 1.235054976651962e+02, 1.091765246124224e+02, 9.146071534295940e+01, 7.094734286807436e+01, 4.932360910287924e+01, 2.943607944100660e+01, 1.452398894737365e+01, 6.144161457768701e+00, 3.365412342591811e+00, 2.605541205687865e+00, 1.643668579645982e+00, 7.359951401140289e-01, 2.448746692758899e-01, 7.279812976637245e-02, 1.029486859260419e-02, 4.647295685880696e-04, 5.696008181783507e-06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_revapbe_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_revapbe", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([9.415834586235360e-05, 9.986636777661086e-05, 1.086613310441001e-04, 1.226200532458488e-04, 1.457247298401533e-04, 1.862951228128392e-04, 2.636057165563846e-04, 4.279981610016708e-04, 8.287453853168814e-04, 1.967796918676240e-03, 6.398377162987067e-03, 2.613729837661576e-02, 4.169819567948328e-02, 7.377813091941064e-02, 1.918995363954420e-01, 6.110838875747370e-01, 1.225997404988971e+00, 7.859930889629225e-01, 2.012552572151456e-01, 2.460748898901443e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_revapbe_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_revapbe", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([5.955589934432027e-01, 6.086682592790550e-01, 6.280159436992272e-01, 6.568825936032122e-01, 7.006044312967044e-01, 7.681673130743746e-01, 8.750993687035944e-01, 1.047284970104187e+00, 1.312928614453458e+00, 1.607745486367439e+00, 2.110598914232311e+00, 4.009771755640747e+00, 4.465834435359663e+00, 5.751734343899990e+00, 7.884599340080366e+00, 4.487880857975601e+00, -4.922451500194024e+00, 1.684522029163662e+02, 1.073551701760963e+03, 9.834327177505476e+03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_revapbe_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_revapbe", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.420204499981249e-07, -4.947886587846182e-07, -5.813995414871961e-07, -7.317693308532731e-07, -1.014174185930293e-06, -1.604737466586529e-06, -3.024377646220837e-06, -6.992427156765939e-06, -1.793669366373286e-05, 1.402429030115364e-05, 1.169234141830840e-03, -3.106617665435867e-02, -8.963904130939855e-02, -2.308938710262971e-01, -5.286952876018931e-01, 5.106040539704026e+01, 3.683780034832717e+03, 1.009302965988433e+05, 3.046689435460070e+06, 2.761849931084892e+08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_revapbe_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_revapbe", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-8.986132148304757e-13, -1.120779379472578e-12, -1.539103931722592e-12, -2.425700517167713e-12, -4.653594046849605e-12, -1.180554515858290e-11, -4.442559269300429e-11, -2.895941448985557e-10, -3.975268776525734e-09, -1.399761242303494e-07, -1.372170537317878e-05, -8.936014178544449e-04, -4.373958034402568e-03, -4.254824370183403e-02, -2.200692208714072e+00, -5.545049633720583e+02, -3.343493371551574e+05, -2.824642930520630e+08, -1.021362825697318e+12, -7.187134361085664e+16]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
