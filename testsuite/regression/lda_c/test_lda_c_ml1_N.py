
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_lda_c_ml1_N_2_zk():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_ml1", 2)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-9.374945926124824e-02, -9.362248384359616e-02, -9.343612727375029e-02, -9.316026108187087e-02, -9.274691210652190e-02, -9.211695777580317e-02, -9.113410113358938e-02, -8.955154332184853e-02, -8.690114172490694e-02, -8.228660987386520e-02, -7.407067773028461e-02, -6.240856497145045e-02, -5.865501944595167e-02, -5.439541562132988e-02, -4.490599362091659e-02, -3.056942115529776e-02, -1.497361198374287e-02, -4.370256860938695e-03, -6.327670827725569e-04, -4.009339775060973e-05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_lda_c_ml1_N_2_vrho():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_ml1", 2)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-9.580487196224607e-02, -9.580594492935077e-02, -9.571361554114573e-02, -9.571590532799885e-02, -9.557904645810814e-02, -9.558400020570527e-02, -9.537839442223847e-02, -9.538932525743024e-02, -9.507431182658285e-02, -9.509913286655282e-02, -9.460226695554978e-02, -9.466102979361986e-02, -9.384235762318861e-02, -9.399021734843925e-02, -9.254771053962138e-02, -9.295444231914052e-02, -9.013095851296604e-02, -9.140341681025298e-02, -8.493277095386335e-02, -8.964932262282381e-02, -7.265372188833806e-02, -9.219864498254164e-02, -5.667812941847712e-02, -1.101532520838968e-01, -5.315807625142362e-02, -1.106456423044664e-01, -4.984644356301013e-02, -1.025387769093647e-01, -4.142496267580933e-02, -9.349527353401929e-02, -2.826141683619400e-02, -7.933374237025832e-02, -1.381893002777462e-02, -5.733621714590987e-02, -4.039218672308254e-03, -3.191547100397456e-02, -5.961368293890393e-04, -1.279383822866462e-02, -3.910302377712495e-05, -3.387655300508886e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_lda_c_ml1_N_2_v2rho2():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_ml1", 2)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.379136609120237e-04, -2.543013124353847e-04, 2.379256504651883e-04, 2.527710100023921e-04, -2.705294571122310e-04, 2.527982104594700e-04, 2.757421912761157e-04, -2.956775439077530e-04, 2.758064420026089e-04, 3.123908529215220e-04, -3.359380506002777e-04, 3.125516912257585e-04, 3.735436293238429e-04, -4.034766213244928e-04, 3.739813038132862e-04, 4.823139289722977e-04, -5.246336546974790e-04, 4.836567624606046e-04, 6.940396184736783e-04, -7.639007154439371e-04, 6.989344509704421e-04, 1.160946670382673e-03, -1.305915252471169e-03, 1.183784096436756e-03, 2.370688958419339e-03, -2.795031530604162e-03, 2.521744425472649e-03, 5.995757500787766e-03, -8.056276725563530e-03, 7.582091833540589e-03, 1.453328566602373e-02, -3.088040752620996e-02, 3.976519735823428e-02, 1.848675243281887e-02, -9.848012322471500e-02, 2.671745483587603e-01, 2.465055137493144e-02, -1.529076684218594e-01, 4.501100247637097e-01, 4.525301769010795e-02, -2.823240810101875e-01, 7.620863951770203e-01, 1.113991155200156e-01, -8.740999798963000e-01, 2.445888528335213e+00, 3.679806933674419e-01, -4.636080700275838e+00, 1.533911533675979e+01, 1.603496510316628e+00, -4.313149652404593e+01, 2.051809107622845e+02, 9.338764904469533e+00, -7.853041424271554e+02, 7.460435614512397e+03, 7.657733597681765e+01, -3.792109047178192e+04, 1.135041827357622e+06, 4.107037844350613e+02, -7.969683316475096e+06, 1.173304626859758e+09]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
