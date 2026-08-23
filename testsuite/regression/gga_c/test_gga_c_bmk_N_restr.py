
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_c_bmk_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_bmk", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.079066929838379e-01, -1.045364936209600e-01, -9.981526092286613e-02, -9.330763249247284e-02, -8.458155913611176e-02, -7.342295702370739e-02, -6.027346820907609e-02, -4.679117409007408e-02, -3.582214822378372e-02, -2.909848118535625e-02, -2.447679868022918e-02, -4.237288029314232e-02, -7.162173565318393e-02, -3.151503088598877e-02, -1.786190502524363e-02, -9.407656171403139e-03, 1.667091193480574e-02, 1.791244797154454e-02, 5.253853955077841e-03, 6.590398734691741e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_c_bmk_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_bmk", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.131746691791504e-01, -3.063007747517305e-01, -2.959016204166284e-01, -2.801237503331012e-01, -2.563921529794298e-01, -2.218088736305317e-01, -1.749310260788904e-01, -1.195860435632268e-01, -6.815762807243253e-02, -4.084933848783954e-02, -3.865123269941920e-02, -1.275326713031934e-01, -1.855113013752716e-01, -8.990117619359651e-02, -2.855313581812782e-02, -3.760115276515064e-02, -2.609606338202164e-02, 1.758737058203403e-02, 6.766270421734688e-03, 8.727822395194993e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_bmk_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_bmk", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.108204389102651e-06, 2.208440729006219e-06, 2.351705023918647e-06, 2.554322726625846e-06, 2.834116833456749e-06, 3.200057223736234e-06, 3.619765506762792e-06, 3.933986917357205e-06, 3.658169831183410e-06, 3.557854771588227e-06, 3.061679473361956e-05, 6.429603961319173e-03, 3.902207932084395e-02, 2.019261552391281e-02, 7.728908575268278e-03, 1.427936115424984e-01, 3.126214992999012e+00, 1.100421394251717e+01, 1.781466832664581e+01, 2.220837147047342e+01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_bmk_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_bmk", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.118323946042022e-03, -2.396852879004617e-03, -2.810897940818018e-03, -3.429092682583456e-03, -4.349178103377429e-03, -5.688910298534918e-03, -7.525217004599440e-03, -9.747173072533144e-03, -1.161768230904655e-02, -3.111986971331563e-03, 3.901047116082108e-02, -4.901010021458727e-01, -1.122734807908936e-01, -1.133890854916277e+00, -9.217899187369993e-01, 8.256191279822144e+00, -8.962574704661000e+01, -4.241655432787092e+02, 6.090367614515550e+03, 7.294426972518195e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_bmk_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_bmk", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.121982960637454e-08, 2.571649731046424e-08, 3.323261678197366e-08, 4.650061994342558e-08, 7.160112612177707e-08, 1.232607368474798e-07, 2.406702681154108e-07, 5.417889823211266e-07, 1.419218482646460e-06, 9.872833934239468e-07, -1.105879142137837e-04, 3.738475683084367e-02, 2.140507533022169e-02, 4.015252553998401e-01, 8.153892262227547e-01, -4.695274430419792e+01, 5.693059432130826e+03, 1.252192961764351e+06, 2.467074056628744e+08, 2.295904898879558e+11]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_bmk_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_bmk", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.277538799387914e-13, -5.312241411535098e-13, -7.180285220483864e-13, -1.087208129644156e-12, -1.911559355939505e-12, -4.075528368963372e-12, -1.109072801042438e-11, -4.105754084178480e-11, -2.223384327192466e-10, -7.779033389024320e-10, 2.154665745754080e-07, -4.287168625833577e-03, -6.229621023547167e-02, -2.031248108201266e-01, -9.342089222431498e-01, 1.526078937514001e+02, -7.021259353227315e+05, -3.909338426147025e+09, -9.036552242999289e+13, -6.486381871904138e+19]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
