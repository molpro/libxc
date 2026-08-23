
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_c_revm06_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_revm06", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-8.523303886113093e-02, -8.447557779131194e-02, -8.337961015445065e-02, -8.179006052951958e-02, -7.947727317929076e-02, -7.609885834485521e-02, -7.114331483645754e-02, -6.385027912933411e-02, -5.302421153888959e-02, -3.623817566742239e-02, -2.331943523937054e-02, -6.735180999157374e-02, -4.719701917067232e-02, -3.365194728919659e-02, -2.243791789335467e-02, -2.497595591502090e-03, 3.833376805364212e-02, 3.237603189047514e-02, 9.209109152700443e-03, 1.144278491614034e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_c_revm06_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_revm06", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.015352465953185e-01, -1.005969568067250e-01, -9.919593879356343e-02, -9.707390363249005e-02, -9.380247754612916e-02, -8.866665588048213e-02, -8.054918206736328e-02, -6.830910391846862e-02, -5.441891914938163e-02, -5.816205184867932e-02, -9.240360862966189e-02, -5.526293992465666e-02, -6.313129767321109e-02, -6.110259086702571e-02, -3.639603742269642e-02, -5.767997446689818e-02, -6.357275117860127e-03, 4.711777231687548e-02, 1.630232602239145e-02, 2.169445495796399e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_revm06_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_revm06", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.361466873090649e-07, -1.579209838024260e-07, -1.945699669842656e-07, -2.602163245192218e-07, -3.879781613079555e-07, -6.645463795036481e-07, -1.344071186376116e-06, -3.234491522892173e-06, -8.608451448772457e-06, -1.373814278843206e-05, 2.338890247043403e-04, 5.820819531864652e-03, 7.578865634460264e-03, 6.295526587163158e-03, -8.891765470683835e-03, 1.686211734395426e-01, 1.376317661270423e+00, -6.529710129475205e+01, -3.185102680145368e+03, -3.687043790107953e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_revm06_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_revm06", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([5.404779022264145e-04, 5.653513219094008e-04, 6.027982470384345e-04, 6.600147555637284e-04, 7.488009626734050e-04, 8.878715058917860e-04, 1.102036389353282e-03, 1.398671456805729e-03, 1.655163179809068e-03, 1.372918055168695e-03, -6.688429189896627e-04, -8.080790152247462e-03, -4.087395162918722e-03, 3.627496016853258e-03, 1.257353354261777e-02, 1.589220704355258e-02, 2.472610684398978e-02, 1.958259163909470e-02, 7.084458377255846e-03, 1.119110482682814e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_revm06_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_revm06", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.813844624079058e-04, -5.380119952369069e-04, -6.291537278453655e-04, -7.824495766297523e-04, -1.055528295743886e-03, -1.576992841462431e-03, -2.643652248319850e-03, -4.852750700716640e-03, -8.023453256456994e-03, 2.318341903471429e-03, 8.200943708425237e-02, 6.430840164730671e-02, 4.254892205749993e-02, -2.274876122769416e-01, -4.933704335330752e-01, 4.494006320209874e+00, -1.932587674837608e+02, -4.768723064363369e+02, 1.920035832832768e+04, 2.312266663607834e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_revm06_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_revm06", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([9.346507280000154e-09, 1.112083980862524e-08, 1.422789055179885e-08, 2.013063537449771e-08, 3.267349506548219e-08, 6.363354876726288e-08, 1.560870269573405e-07, 4.985189656883328e-07, 1.978694473924842e-06, 6.462324887368943e-06, -9.973747096379611e-06, -1.308797300787931e-02, -4.102219053455390e-02, 1.224632811951501e-01, 1.155983070107451e+00, 8.511369671927529e+00, 1.587484800354805e+04, 1.780749707564583e+06, -2.592405749228526e+09, -2.943049290468056e+14]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_revm06_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_revm06", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.056381544068550e-05, -1.174821965315369e-05, -1.364711099466767e-05, -1.682414415297526e-05, -2.244490331343346e-05, -3.309380633716891e-05, -5.479673458381802e-05, -1.014542077044979e-04, -2.032595695006146e-04, -5.058249139681098e-04, -2.657624603559414e-03, 7.744317991529113e-03, 1.997058266070525e-02, -8.031622306816930e-02, -4.997861468770740e-01, -4.698258265720304e+00, -3.323348291471861e+01, 2.958628201370876e+01, 6.534160376003500e+03, 8.942586873655904e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_revm06_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_revm06", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.817367986625001e-13, -2.293843353430761e-13, -3.197116912731095e-13, -5.123528872790742e-13, -9.972430244400569e-13, -2.533761982610786e-12, -9.196313393292763e-12, -5.293976640819319e-11, -5.459599137873502e-10, -1.358179021234525e-08, -2.289729289376608e-06, -7.885883483484680e-04, 9.755535125689715e-04, -1.274168795064006e-01, -3.733386451779388e+00, -8.134548065699183e+02, -2.012292216945846e+06, -7.874677612946179e+09, -1.803058203701687e+14, -1.335522210018181e+20]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_revm06_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_revm06", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.147076203534866e-10, 2.551036727678975e-10, 3.262637219442242e-10, 4.628826355371139e-10, 7.587977938916938e-10, 1.515967862500039e-09, 3.942901684452679e-09, 1.440419032802509e-08, 8.076495262773256e-08, 8.098280249042033e-07, 2.022513164370345e-05, 7.323392766785541e-04, 3.989672533237821e-03, 1.024753339833855e-01, 1.866700712105839e+00, 8.300196778869697e+01, 9.093236283547914e+03, 4.051152746099796e+06, 1.809211324329324e+10, 1.634427499199752e+15]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_revm06_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_revm06", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.737454839083922e-07, -3.065028655816412e-07, -3.603788804740260e-07, -4.541181047748061e-07, -6.304414803454952e-07, -9.989916470854429e-07, -1.882033845124858e-06, -4.371480289744651e-06, -1.262724766131398e-05, -4.288936865293717e-05, -1.479324310067899e-04, -8.505663470023832e-04, -1.012744709350711e-02, -1.197064825480132e-01, -9.803112178267450e-01, -7.842910642594512e+00, -8.704063367002617e+01, -1.826188512657333e+03, -7.959549423474871e+04, -9.920566395957006e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
