
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_lda_c_ob_pz_N_2_zk():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_ob_pz", 2)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.173538700257214e-01, -1.167530811828752e-01, -1.158907913734233e-01, -1.146544735527396e-01, -1.128846466263783e-01, -1.103569410116959e-01, -1.067592287569828e-01, -1.016655156741442e-01, -9.451924644586961e-02, -8.468753148959204e-02, -7.152974720882881e-02, -5.690829072261974e-02, -5.275512900796174e-02, -4.854043368824506e-02, -4.181766956498069e-02, -3.134095143950330e-02, -1.882891784936139e-02, -8.184952271354578e-03, -2.332033458866447e-03, -3.421209384909312e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_lda_c_ob_pz_N_2_vrho():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_ob_pz", 2)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.271702516957622e-01, -1.271725961609466e-01, -1.265600894241629e-01, -1.265650659212910e-01, -1.256831948109247e-01, -1.256938780333659e-01, -1.244233245078806e-01, -1.244466358221555e-01, -1.226136205747860e-01, -1.226657049289342e-01, -1.200136342221655e-01, -1.201340824994083e-01, -1.162720025977840e-01, -1.165649133312702e-01, -1.108532985248319e-01, -1.116199937094562e-01, -1.028469148402454e-01, -1.050786030734989e-01, -9.035103695964397e-02, -9.781668367676093e-02, -6.983024668424380e-02, -9.666714948803287e-02, -5.058796090241164e-02, -1.106702863490087e-01, -4.699292387712629e-02, -1.083644721417383e-01, -4.111090564681872e-02, -9.618680396592540e-02, -3.596546148620528e-02, -8.791771174049701e-02, -2.788333756938584e-02, -7.512722987375137e-02, -1.809006179787315e-02, -5.428685410595119e-02, -8.926580034088161e-03, -2.752489215839236e-02, -2.859511550477665e-03, -7.465425507868371e-03, -4.444358781419082e-04, -8.433953749837236e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_lda_c_ob_pz_N_2_v2rho2():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_ob_pz", 2)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([4.821963096814492e-04, -5.933092590318900e-04, 4.822202181672349e-04, 5.096246550022766e-04, -6.276904633060526e-04, 5.096785866899439e-04, 5.517468510765350e-04, -6.805796366893468e-04, 5.518731987704722e-04, 6.182984780064281e-04, -7.643557158423380e-04, 6.186110231932223e-04, 7.277986029938198e-04, -9.027381551012377e-04, 7.286346069037276e-04, 9.186492317587206e-04, -1.145451521107032e-03, 9.211511594489107e-04, 1.279411899323763e-03, -1.609217054523614e-03, 1.288209038637795e-03, 2.042055845840336e-03, -2.609976042431009e-03, 2.081015057003488e-03, 3.902253952471094e-03, -5.168883604745123e-03, 4.141365295228610e-03, 9.018653374549568e-03, -1.329102669855135e-02, 1.127852801002473e-02, 1.895930028428494e-02, -4.226084586871117e-02, 4.914167013425567e-02, 1.541674160264705e-02, -9.321026680306359e-02, 2.128784053270120e-01, 1.805327963642845e-02, -1.329990671086890e-01, 3.290894862840608e-01, 4.366492026184886e-02, -2.251082111943163e-01, 5.859400159706153e-01, 1.022330319769674e-01, -6.485741864171890e-01, 1.734125382950648e+00, 2.630190960771399e-01, -3.039994502807445e+00, 9.087895033135405e+00, -1.418076316213607e-01, -2.444417325259345e+01, 8.880587559899658e+01, -3.816670450959464e+01, -3.592205588238432e+02, 1.799353670740237e+03, -2.394959992830247e+03, -1.055249597395594e+04, 8.997110649065724e+04, -3.437035042917250e+05, -8.275849284502910e+05, 1.472965149197540e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
