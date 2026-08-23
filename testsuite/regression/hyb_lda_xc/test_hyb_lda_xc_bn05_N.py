
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_lda_xc_bn05_N_2_zk():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_lda_xc_bn05", 2)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.849753938549020e+00, -3.765929541162465e+00, -3.648485286986288e+00, -3.485826329943383e+00, -3.264251823344989e+00, -2.969517811143974e+00, -2.590594641767718e+00, -2.126654869708597e+00, -1.597742133984837e+00, -1.059098437555519e+00, -6.236497379205935e-01, -4.318881714923249e-01, -3.599088537337088e-01, -2.603449577788203e-01, -1.403427276362575e-01, -4.519446359077892e-02, -6.053359133979690e-03, -2.543325783887722e-04, -2.626464758683406e-06, -3.965058510339362e-09]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_lda_xc_bn05_N_2_vrho():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_lda_xc_bn05", 2)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.233165379526420e+00, -5.233122596091381e+00, -5.121124063419608e+00, -5.121034696669579e+00, -4.964140506055425e+00, -4.963953037699675e+00, -4.746710855298361e+00, -4.746315126914550e+00, -4.450514042906486e+00, -4.449670929812391e+00, -4.056509177167245e+00, -4.054687889057019e+00, -3.550000498781585e+00, -3.545983289157701e+00, -2.930151648993611e+00, -2.921007827570217e+00, -2.224884239389129e+00, -2.203098230991351e+00, -1.511786325595501e+00, -1.457046590205167e+00, -9.442540614758281e-01, -8.100499772905470e-01, -6.801617910627340e-01, -4.653234556531735e-01, -5.712512393366000e-01, -3.834536480172354e-01, -4.209699738728457e-01, -2.905734403042463e-01, -2.372395454740945e-01, -1.646744456574707e-01, -8.328625471557408e-02, -5.597948110326780e-02, -1.200673098584067e-02, -7.553149185093258e-03, -5.094912432594109e-04, -3.405576801717335e-04, -5.222248623516730e-06, -3.954718579951651e-06, -7.896775719916631e-09, -5.991580259422454e-09]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_lda_xc_bn05_N_2_v2rho2():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_lda_xc_bn05", 2)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.013979684393222e-02, -5.131587608903957e-04, -2.014010770670314e-02, -2.096730135775133e-02, -5.435281097011265e-04, -2.096799132844540e-02, -2.221541091559829e-02, -5.903226884708204e-04, -2.221699015135290e-02, -2.413705785540385e-02, -6.646225719623320e-04, -2.414083587307114e-02, -2.718397190032690e-02, -7.877820954453275e-04, -2.719360303193075e-02, -3.222146655513775e-02, -1.004908886946073e-03, -3.224836480584775e-02, -4.105741038361875e-02, -1.422953403337008e-03, -4.114303332130878e-02, -5.788483669743147e-02, -2.335323179126919e-03, -5.821329748883732e-02, -9.361022840296063e-02, -4.707617760223775e-03, -9.524582297065093e-02, -1.785860529613930e-01, -1.241454520108730e-02, -1.899476803202325e-01, -3.718382217961294e-01, -4.087264598949696e-02, -4.703279687493743e-01, -5.943833953199241e-01, -1.089270831410589e-01, -9.960466433805323e-01, -7.537658535505684e-01, -1.619546923187571e-01, -1.251386576769518e+00, -1.119404149602686e+00, -2.873423481591845e-01, -1.715631857032758e+00, -2.177325475112252e+00, -8.057948343212615e-01, -2.974870410346810e+00, -5.353949686835503e+00, -2.809176400289203e+00, -5.928071513371838e+00, -1.127046224852647e+01, -6.511087928345677e+00, -8.198954302285630e+00, -1.553172928378785e+01, -1.029069178833849e+01, -3.267558733149524e+00, -1.795574431946295e+01, -1.408064283642415e+01, 1.599012371770571e+01, -2.024329626919053e+01, -1.593200898310311e+01, 7.797061008432830e+01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
