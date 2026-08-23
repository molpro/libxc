
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_lda_x_yukawa_N_2_zk():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_x_yukawa", 2)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.019473497800127e+00, -3.935488793250335e+00, -3.817794622392443e+00, -3.654735855836462e+00, -3.432501869826115e+00, -3.136642014955411e+00, -2.755725842970596e+00, -2.288131876819709e+00, -1.752335564780578e+00, -1.200854019843648e+00, -7.463742357621688e-01, -5.468542714321701e-01, -4.686075133769421e-01, -3.558655690271937e-01, -2.168289587105481e-01, -9.529824988579537e-02, -2.327500899939350e-02, -1.685633351602664e-03, -1.899509509124653e-05, -2.672090014920937e-08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_lda_x_yukawa_N_2_vrho():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_x_yukawa", 2)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.405413779698179e+00, -5.405368769504228e+00, -5.293395279237769e+00, -5.293301170273671e+00, -5.136428682921257e+00, -5.136230985324309e+00, -4.918990418210550e+00, -4.918572211345997e+00, -4.622712429739251e+00, -4.621818566627307e+00, -4.228447557047796e+00, -4.226507059230037e+00, -3.721268330246730e+00, -3.716954255340240e+00, -3.099855193734439e+00, -3.089905203671611e+00, -2.391230582779598e+00, -2.366957851028010e+00, -1.672060054148243e+00, -1.608212817256740e+00, -1.099138635673011e+00, -9.278943832105055e-01, -8.363947195799269e-01, -5.273058721498430e-01, -7.208795190693271e-01, -4.334369376981629e-01, -5.554080843486746e-01, -3.346033913619136e-01, -3.479228266801010e-01, -1.927873583252452e-01, -1.609326360396779e-01, -7.057735885893834e-02, -4.280225300124894e-02, -1.034934826580738e-02, -3.395474581761418e-03, -2.585209554914057e-04, -3.863810350255804e-05, -7.959143059240173e-07, -5.366856177202000e-08, -2.306750146817460e-10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_lda_x_yukawa_N_2_v2rho2():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_x_yukawa", 2)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.064814613166188e-02, -3.522101828684134e-133, -2.064848102965236e-02, -2.150754443150652e-02, 0.000000000000000e+00, -2.150828883825126e-02, -2.280504361544092e-02, -1.584945822907860e-132, -2.280675113020638e-02, -2.480568263231476e-02, 0.000000000000000e+00, -2.480978071023386e-02, -2.798492802659085e-02, -1.408840731473654e-132, -2.799542619069736e-02, -3.325934926791367e-02, -7.044203657368268e-133, -3.328889184970295e-02, -4.256175987199219e-02, 7.044203657368268e-133, -4.265695005570872e-02, -6.043941553178061e-02, -2.817681462947307e-132, -6.081214006877230e-02, -9.899850369157052e-02, 5.635362925894614e-132, -1.009247226807496e-01, -1.932572621775185e-01, -2.817681462947307e-132, -2.076569818299530e-01, -4.143843122425659e-01, -8.453044388841921e-132, -5.591878371582354e-01, -6.701358230842234e-01, -1.127072585178923e-131, -1.455414864477600e+00, -8.649769834685416e-01, -4.508290340715691e-131, -1.991193429135045e+00, -1.337171887093872e+00, -2.254145170357846e-131, -2.961678961544030e+00, -2.793119870725433e+00, 4.508290340715691e-131, -6.428230999599525e+00, -8.100567205194377e+00, -1.352487102214707e-130, -2.005538095513298e+01, -3.092871987598769e+01, 3.606632272572553e-130, -7.028825989717218e+01, -9.838775736555353e+01, 0.000000000000000e+00, -1.305951184168765e+02, -1.369937908123537e+02, -2.885305818058042e-129, -1.394259814959852e+02, -1.395931185207040e+02, 1.442652909029021e-129, -1.396254617823307e+02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
