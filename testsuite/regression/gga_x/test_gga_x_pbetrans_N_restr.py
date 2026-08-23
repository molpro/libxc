
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_x_pbetrans_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_pbetrans", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.305202443360058e+00, -4.223598385822300e+00, -4.109375933828113e+00, -3.951412294963419e+00, -3.736724832931445e+00, -3.452183519319980e+00, -3.088493925551791e+00, -2.647302805835086e+00, -2.150044510573833e+00, -1.635774651591339e+00, -1.108587455620012e+00, -6.652179322198888e-01, -5.628607800725496e-01, -4.729426867367611e-01, -3.528757835764932e-01, -2.399191612161579e-01, -1.213277724660830e-01, -4.209807178705973e-02, -8.817945613585638e-03, -9.755393903977053e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_x_pbetrans_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_pbetrans", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.371613911220831e+00, -5.256770548243995e+00, -5.095710311191555e+00, -4.872323428709166e+00, -4.567376017268774e+00, -4.160463757524159e+00, -3.634993001918571e+00, -2.988330360947844e+00, -2.251289640077671e+00, -1.524912162239069e+00, -9.776424203599464e-01, -7.962213138671955e-01, -7.147795363739701e-01, -5.515674910521583e-01, -3.496925491562513e-01, -1.948435172118886e-01, -1.392041168092839e-01, -5.478668521529226e-02, -1.174378409202183e-02, -1.300700015919667e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_pbetrans_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_pbetrans", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.955608228905409e-06, -4.282584608406920e-06, -4.799535300051126e-06, -5.651039818166273e-06, -7.138063338640798e-06, -9.959561557061245e-06, -1.597528427115805e-05, -3.103807419633886e-05, -7.765211171729165e-05, -2.640272930731463e-04, -1.332987458573071e-03, -7.280937079936444e-03, -1.326352090503222e-02, -2.935892228531617e-02, -1.138331277606217e-01, -6.696081044251934e-01, -1.529749248000863e+00, -3.028718476662740e+00, -3.669270746881245e+00, -4.053477784758053e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_pbetrans_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_pbetrans", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.243722854101527e-02, -1.302494059503144e-02, -1.392012792497930e-02, -1.531811123483764e-02, -1.758044367400428e-02, -2.143019254031357e-02, -2.844701697915338e-02, -4.236755748848506e-02, -7.177980286685959e-02, -1.252563308483519e-01, -2.368376919283188e-01, -5.877932365141088e-01, -6.858419400814076e-01, -1.239480049183880e+00, -2.761562089864496e+00, 4.356747546210893e-01, -6.073348123646502e+01, -4.064026042150841e+02, -1.351737414308482e+04, -1.122799111725855e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_pbetrans_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_pbetrans", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.617069395171164e-08, 2.997757792128246e-08, 3.641836361260724e-08, 4.810744452131696e-08, 7.154435707469909e-08, 1.256072537382146e-07, 2.768915435939311e-07, 8.219156158349374e-07, 3.407858549947881e-06, 1.570433761399371e-05, 9.054563212662006e-05, 1.277921259710355e-02, 3.952141823909101e-02, 1.406954186694838e-01, 9.627619180010546e-01, -3.220780037030075e+01, 9.140670699400706e+02, -3.628158136223159e+05, -5.129987852586094e+07, -4.199535598000687e+10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_pbetrans_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_pbetrans", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.518882059786362e-14, 4.480424179819018e-14, 6.338065000228445e-14, 1.042433785256773e-13, 2.126205915052135e-13, 5.889770463593807e-13, 2.514490279936990e-12, 1.964287299842786e-11, 3.493891678314243e-10, 1.771241438456273e-08, 2.705349651964107e-06, 2.323508144515864e-04, 1.296127172491817e-03, 1.581809612129604e-02, 1.227414821523717e+00, 5.831428402004669e+02, 7.883085534605960e+04, 1.100295840350406e+09, 1.863098136917802e+13, 1.183911202226280e+19]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
