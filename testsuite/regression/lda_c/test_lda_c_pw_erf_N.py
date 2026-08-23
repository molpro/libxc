
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_lda_c_pw_erf_N_2_zk():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_pw_erf", 2)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.143677896576687e-01, -1.137192291710738e-01, -1.127871440711376e-01, -1.114481756419837e-01, -1.095259578559344e-01, -1.067690356422181e-01, -1.028202404452452e-01, -9.717550004418594e-02, -8.913849923343595e-02, -7.784851467877027e-02, -6.278616632064167e-02, -4.802106564189661e-02, -4.330481161178652e-02, -3.736321935385347e-02, -2.597325180888798e-02, -1.080680180483152e-02, -1.288513124718157e-03, -2.428035594198401e-05, -7.094001663052532e-08, -2.068359909344550e-11]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_lda_c_pw_erf_N_2_vrho():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_pw_erf", 2)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.249594112886412e-01, -1.249611762796497e-01, -1.243125642055295e-01, -1.243163124406347e-01, -1.233822391142940e-01, -1.233902909739754e-01, -1.220441725427250e-01, -1.220617587459930e-01, -1.201193156574066e-01, -1.201586605273615e-01, -1.173485232861504e-01, -1.174396760081897e-01, -1.133519536750569e-01, -1.135741495520325e-01, -1.075537859265307e-01, -1.081369923792862e-01, -9.900714870418409e-02, -1.007080295656464e-01, -8.592505739874076e-02, -9.159092064144791e-02, -6.573891614641510e-02, -8.558018912519685e-02, -4.736753753415766e-02, -9.194045815566659e-02, -4.315427757028707e-02, -8.797448820307663e-02, -3.839782123553093e-02, -7.614420179342601e-02, -2.823716573588236e-02, -6.057653564940978e-02, -1.304986573629091e-02, -3.761197331700014e-02, -1.649386888270314e-03, -8.728202243382534e-03, -2.840011509080551e-05, -3.800400976072217e-04, -7.353961408887682e-08, -3.517473615864059e-06, -2.079192319619977e-11, -4.830860269334210e-09]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_lda_c_pw_erf_N_2_v2rho2():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_pw_erf", 2)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.459322183540784e-04, -4.637439042933825e-04, 3.459503695045278e-04, 3.656608234911518e-04, -4.909504623972056e-04, 3.657017849417733e-04, 3.959567512382160e-04, -5.328375142128870e-04, 3.960527686781161e-04, 4.438171301461362e-04, -5.992649978489791e-04, 4.440548378590694e-04, 5.225402360904876e-04, -7.091756557519129e-04, 5.231767480306446e-04, 6.596530151910724e-04, -9.024079418531088e-04, 6.615605338094499e-04, 9.184025827314293e-04, -1.272828045689808e-03, 9.251199284650603e-04, 1.463088634781295e-03, -2.075527024389872e-03, 1.492866017188590e-03, 2.776159847272201e-03, -4.137328982658738e-03, 2.958493502164649e-03, 6.250504233574667e-03, -1.068930966344104e-02, 7.946812466203095e-03, 1.194442025965268e-02, -3.400129647376724e-02, 3.353831900043249e-02, 1.011352198314075e-02, -8.793067808248502e-02, 1.762202043604906e-01, 1.126288102617427e-02, -1.279219691014621e-01, 2.746457060080372e-01, 1.466145021441749e-02, -2.172121735114995e-01, 4.186126279814725e-01, -5.917701433205053e-03, -5.650073000601334e-01, 1.087331050416322e+00, -2.658600607586354e-01, -2.328447965364363e+00, 3.312344181588261e+00, -6.612703672785614e-01, -8.553113315732006e+00, 3.082162710522510e+00, -2.201159979417753e-01, -1.253631238007461e+01, 2.602061718880577e-02, -1.099236455775099e-02, -1.256642842815199e+01, -7.490564312320203e-04, -1.348420046269894e-04, -1.256637062504888e+01, -3.504566848278046e-06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
