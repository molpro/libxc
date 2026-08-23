
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_xc_dlb97_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_dlb97", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.499416227898728e+00, -4.421460857725068e+00, -4.312473629451294e+00, -4.161996069398850e+00, -3.957935483431226e+00, -3.688245201926310e+00, -3.344592168691410e+00, -2.928090002459426e+00, -2.452785521196801e+00, -1.927052029730209e+00, -1.295685870009622e+00, -6.889788058791567e-01, -5.608274633223881e-01, -4.884509322228855e-01, -3.673118823548114e-01, -2.286896561510208e-01, -1.091772216344210e-01, -3.017692965758225e-02, -3.760261075953354e-03, -2.091356890083032e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_xc_dlb97_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_dlb97", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.065957282844490e+00, -4.950094277455680e+00, -4.788058415437074e+00, -4.564216663475451e+00, -4.260396346390901e+00, -3.858353886023095e+00, -3.345785749913498e+00, -2.729231570144535e+00, -2.060215202679842e+00, -1.459868927872934e+00, -9.827997649104350e-01, -7.437233710832787e-01, -6.729171547313377e-01, -5.211491965263115e-01, -3.545678118033827e-01, -2.063806224253901e-01, -1.046419833505558e-01, -3.995008813626902e-02, -5.418333242817857e-03, -2.968217062178291e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_xc_dlb97_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_dlb97", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.015632219996285e-05, -1.095560912277130e-05, -1.220794810401496e-05, -1.424400205018226e-05, -1.773295906233330e-05, -2.417314119296486e-05, -3.735998260953080e-05, -6.841861461968987e-05, -1.556789117233467e-04, -4.589444742860560e-04, -2.065100158146944e-03, -1.465638693884767e-02, -2.978936820890072e-02, -5.111250475737857e-02, -1.389781004442034e-01, -6.152472565868843e-01, -3.555380488276639e+00, -8.567459312259645e+00, -1.061789444329776e+01, -1.150147198864676e+01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_xc_dlb97_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_dlb97", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.461453719592685e-02, -1.524157543497295e-02, -1.619309457176813e-02, -1.767112613872392e-02, -2.004276242019925e-02, -2.401176619808914e-02, -3.095014255224867e-02, -4.311306881529552e-02, -5.974098871878642e-02, -4.839089727849674e-02, -2.238455851369905e-02, -5.034428646328786e-01, -8.797890154812648e-01, -9.234597270643619e-01, -1.746812940681455e+00, -3.984760208738707e+00, 5.867853134574312e+01, -1.286916287844655e+02, -8.054883992567888e+03, -3.255876218703596e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_xc_dlb97_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_dlb97", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([5.534059469474064e-08, 6.194497574239910e-08, 7.288697065786319e-08, 9.218095944875272e-08, 1.293581524919414e-07, 2.103472623113053e-07, 4.166713211447109e-07, 1.026141594900324e-06, 2.512475468552690e-06, -1.253362276080216e-05, -4.640495477436308e-04, 8.568053601559600e-03, 1.217518528813681e-01, 4.805948621600629e-02, 1.003118855983534e-01, -1.157885208275927e+01, -7.262330480299971e+03, -9.845544550030738e+05, -1.483210883621868e+08, -1.192092259526564e+11]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_xc_dlb97_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_dlb97", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.112759060843530e-13, 2.751358228771910e-13, 3.970066263370651e-13, 6.585868684784274e-13, 1.321249076845622e-12, 3.447148084186290e-12, 1.305848090538793e-11, 8.515172484759587e-11, 1.202055371181778e-09, 4.536567422388631e-08, 5.594231298656551e-06, 1.727536871519121e-03, -1.053873828715238e-02, 9.235924454361465e-02, 2.206364519562308e+00, 3.961552866042925e+02, 8.079323921707787e+05, 3.010339952989507e+09, 5.381892296274529e+13, 3.359186917316801e+19]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
