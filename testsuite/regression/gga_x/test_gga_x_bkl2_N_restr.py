
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_x_bkl2_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_bkl2", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.231203278410572e+00, -4.148350195105471e+00, -4.032310844468930e+00, -3.871690988567026e+00, -3.653093292259646e+00, -3.362745829772363e+00, -2.990372132203759e+00, -2.536303534314408e+00, -2.021565755752764e+00, -1.493980303308536e+00, -9.979903773806320e-01, -6.468501526594751e-01, -5.557193625544380e-01, -4.568576481420204e-01, -3.272730905468561e-01, -2.104176889846852e-01, -1.203964245053576e-01, -3.608753068902285e-02, -4.865190916313961e-03, -5.377875301790263e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_x_bkl2_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_bkl2", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.461747036939073e+00, -5.348089168950966e+00, -5.188717553719398e+00, -4.967719537173898e+00, -4.666105105726382e+00, -4.263698082656183e+00, -3.743817168209432e+00, -3.102190705809457e+00, -2.361910437831693e+00, -1.602306011160461e+00, -1.015757807484123e+00, -8.171849444611504e-01, -7.237025671523178e-01, -5.691206112975983e-01, -3.682199912317182e-01, -1.886489608343541e-01, -1.262059388640131e-01, -6.035701231242086e-02, -6.515487007525002e-03, -7.170500402387017e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_bkl2_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_bkl2", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.929834658595321e-06, -2.092115982268836e-06, -2.349302563424898e-06, -2.774489433068253e-06, -3.521276487392921e-06, -4.951400498312995e-06, -8.048706403827343e-06, -1.602605003264286e-05, -4.208038575752914e-05, -1.568048592599382e-04, -8.387095043739982e-04, -3.633564515752396e-03, -6.411019829577659e-03, -1.486951121075046e-02, -6.420955215023741e-02, -4.921467757984940e-01, -2.326705644684034e+00, 2.758207488714555e+01, 7.777527077456869e+00, 6.371562524777627e-261]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_bkl2_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_bkl2", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.144514081273836e-02, -1.196433437560442e-02, -1.275399497031860e-02, -1.398504866098880e-02, -1.597416031642349e-02, -1.935971310499816e-02, -2.557443279038572e-02, -3.828635602267490e-02, -6.826499667922058e-02, -1.475688484512757e-01, -3.500211219432145e-01, -5.299352433958746e-01, -6.408465446781694e-01, -1.113958415756628e+00, -2.831920976829656e+00, -6.868317664876901e+00, 1.319595594593654e+02, -4.876181853206066e+02, -9.585600508291633e+03, -6.190863068898107e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_bkl2_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_bkl2", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.372570296413606e-08, 1.578998177174754e-08, 1.930713352143892e-08, 2.575955846346990e-08, 3.891984603292950e-08, 7.014736946842457e-08, 1.620014914421761e-07, 5.267184710807277e-07, 2.686813640684136e-06, 2.292193147940320e-05, 3.709408029045679e-04, 7.231128443526373e-03, 2.011767731207311e-02, 8.388359730917375e-02, 9.422021500433947e-01, 7.853258233777554e+00, -1.184937140643582e+04, -3.098048238742446e+05, 5.395208641270047e+08, 2.717146457681065e-248]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_bkl2_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_bkl2", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([6.891454398394100e-15, 8.795988005362554e-15, 1.248857235652806e-14, 2.065562910698059e-14, 4.250319180158622e-14, 1.194445314839806e-13, 5.227531498284339e-13, 4.275615048409143e-12, 8.334286373547194e-11, 5.048548447417945e-09, 8.659505680102362e-07, 4.745633388217578e-05, 2.495157775695025e-04, 3.320897502163751e-03, 3.162510071102516e-01, 2.597859687826058e+02, 1.017405091559468e+06, -1.876701651573900e+09, -1.567792160961743e+14, -5.749649354996289e-240]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
