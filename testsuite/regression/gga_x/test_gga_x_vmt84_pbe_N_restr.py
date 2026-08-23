
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_x_vmt84_pbe_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_vmt84_pbe", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.304670209407425e+00, -4.223021244427956e+00, -4.108729607876721e+00, -3.950656224946529e+00, -3.735787385216752e+00, -3.450928733257686e+00, -3.086639652403806e+00, -2.644202818831181e+00, -2.144127691891189e+00, -1.624138509821787e+00, -1.096824834379354e+00, -6.649346834309550e-01, -5.628334048487733e-01, -4.726077771705658e-01, -3.513013810417443e-01, -2.345403300183911e-01, -1.284501957278509e-01, -2.890818985534492e-02, -3.918709308766150e-03, -2.404906643237137e-09]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_x_vmt84_pbe_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_vmt84_pbe", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.374641504169803e+00, -5.259982733207345e+00, -5.099204500689058e+00, -4.876259665724253e+00, -4.572030639232969e+00, -4.166345231684301e+00, -3.643110306854527e+00, -3.000834076952120e+00, -2.272727829546248e+00, -1.560854218769905e+00, -1.010594038676812e+00, -7.975193699701149e-01, -7.149813795350390e-01, -5.530033654527027e-01, -3.549990337804841e-01, -2.060201672511367e-01, -1.424674389012655e-01, -8.136701426297901e-02, -7.458048378425289e-03, -1.082307068654229e-08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_vmt84_pbe_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_vmt84_pbe", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.915508380479357e-06, -4.237075478578357e-06, -4.745014092407444e-06, -5.580523025243077e-06, -7.036485477800102e-06, -9.789508133676196e-06, -1.562502886652715e-05, -3.008429689538887e-05, -7.395176932571947e-05, -2.433206927347076e-04, -1.203450316103470e-03, -7.146471930200824e-03, -1.317497355752065e-02, -2.865955620032166e-02, -1.068550371517650e-01, -5.713563490303782e-01, -1.952296155137777e+00, 9.649601300732064e+01, 6.080006458083061e+02, 1.610400215604843e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_vmt84_pbe_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_vmt84_pbe", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.235027997618441e-02, -1.292741499627823e-02, -1.380520132513770e-02, -1.517285171782416e-02, -1.737778893202694e-02, -2.110568698684207e-02, -2.781949834288108e-02, -4.081426042609279e-02, -6.668474439716138e-02, -1.055508690864081e-01, -1.800851563497510e-01, -5.777785219593843e-01, -6.831843728264512e-01, -1.208499556811727e+00, -2.472486967457782e+00, 1.774245422697387e+00, 7.525003751577970e+01, -4.700740007461262e+03, -2.497043233129909e+03, -2.186248945224999e+02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_vmt84_pbe_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_vmt84_pbe", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.517728743031074e-08, 2.879025434936306e-08, 3.488538867664258e-08, 4.589809982495662e-08, 6.782271598541281e-08, 1.177982067361113e-07, 2.546534634303986e-07, 7.261435169014187e-07, 2.711202009978905e-06, 6.956862444792444e-06, -7.882139570532220e-05, 1.191953993196634e-02, 3.847331033807228e-02, 1.283528653561881e-01, 6.655010473826142e-01, -4.108923726869727e+01, -8.379242895137573e+03, 8.693640112543717e+06, -1.689963836149031e+09, 4.424920430662221e+10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_vmt84_pbe_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_vmt84_pbe", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([4.264448942178559e-14, 5.425772419490333e-14, 7.667002210894112e-14, 1.258908524330625e-13, 2.561046225986493e-13, 7.064266617206184e-13, 2.994096492457997e-12, 2.308179959779029e-11, 4.001498557155006e-10, 1.934772719306220e-08, 2.870113623444801e-06, 2.781045606823023e-04, 1.578836857359421e-03, 1.878167468141359e-02, 1.376659652806576e+00, 5.704422073370281e+02, 7.477077984699155e+05, -2.859807147531052e+10, -3.126574947545225e+14, -1.053173283818794e+19]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
