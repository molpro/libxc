
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_lda_x_rae_N_2_zk():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_x_rae", 2)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.552295566984519e-01, -2.500739189582387e-01, -2.428485147168526e-01, -2.328372443507306e-01, -2.191909709626991e-01, -2.010197909180171e-01, -1.776161929597398e-01, -1.488687123963620e-01, -1.158872884210879e-01, -8.184901918203447e-02, -5.362199913802530e-02, -4.108789950053490e-02, -3.613368164973216e-02, -2.892776857494428e-02, -1.981331795738346e-02, -1.128942150531163e-02, -5.126339712798320e-03, -1.713762064323702e-03, -3.677687524416017e-04, -4.133319844776659e-05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_lda_x_rae_N_2_vrho():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_x_rae", 2)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.403074563197325e-01, -3.403046948425263e-01, -3.334347788438484e-01, -3.334290048948093e-01, -3.238040842763547e-01, -3.237919542869725e-01, -3.104624881240691e-01, -3.104368269628938e-01, -2.922820465265035e-01, -2.922271939312924e-01, -2.680858974407977e-01, -2.679667989578253e-01, -2.369537922352710e-01, -2.366889447054837e-01, -1.987957781475472e-01, -1.981846323762399e-01, -1.552517681383525e-01, -1.537593795792418e-01, -1.109930762242680e-01, -1.070581299372068e-01, -7.561991788171574e-02, -6.500357194905691e-02, -5.931658928736058e-02, -3.997515301314976e-02, -5.211694915840556e-02, -3.403030197825788e-02, -4.174605479838737e-02, -2.770030719584149e-02, -2.855910403644488e-02, -1.836519570366080e-02, -1.618802774449828e-02, -9.588291088309950e-03, -7.252194406466993e-03, -3.703576015787139e-03, -2.370289850593820e-03, -9.467227999020270e-04, -4.975826116589864e-04, -1.359198890241425e-04, -5.530912811467805e-05, -8.992288303873548e-06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_lda_x_rae_N_2_v2rho2():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_x_rae", 2)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.266810462176653e-03, 0.000000000000000e+00, -1.266831021883661e-03, -1.319571044997302e-03, -1.079684155803933e-134, -1.319616747091753e-03, -1.399232636382727e-03, -9.717157402235398e-134, -1.399337475275204e-03, -1.522075879318246e-03, 2.159368311607866e-134, -1.522327523745537e-03, -1.717316299456547e-03, -6.478104934823599e-134, -1.717961058730359e-03, -2.041299051149508e-03, -1.079684155803933e-133, -2.043113974848184e-03, -2.612926803358420e-03, -6.478104934823599e-134, -2.618777641796630e-03, -3.712275995270977e-03, -1.727494649286293e-133, -3.735206530606304e-03, -6.086693892494185e-03, 3.023115636251013e-133, -6.205422201745828e-03, -1.190865721818069e-02, 1.727494649286293e-133, -1.280015607477754e-02, -2.565559955183549e-02, -6.909978597145172e-133, -3.472003285468239e-02, -4.169675222224990e-02, 0.000000000000000e+00, -9.180668406082720e-02, -5.401278877961006e-02, -6.218980737430655e-132, -1.266843493257725e-01, -8.418286331786903e-02, -2.763991438858069e-132, -1.911989047861015e-01, -1.798727663878593e-01, 9.673970036003241e-132, -4.349741516619262e-01, -5.598435653714326e-01, -3.316789726629682e-131, -1.595776814103559e+00, -2.789431468493265e+00, -1.326715890651873e-130, -1.069576974837859e+01, -2.611269266143540e+01, 0.000000000000000e+00, -1.636850058924205e+02, -5.925488786077774e+02, 0.000000000000000e+00, -7.941244152039172e+03, -4.795798707766035e+04, -5.796510173984076e-126, -1.814320994812149e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
