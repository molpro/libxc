
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_x_ktbm_1_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_1", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.784582045750331e+00, -4.690964001355579e+00, -4.559806003120996e+00, -4.378160559988009e+00, -4.130703113779735e+00, -3.801372025529095e+00, -3.377107319168878e+00, -2.853708809272671e+00, -2.240517729743525e+00, -1.567408955081245e+00, -9.619475732173096e-01, -6.319668728136173e-01, -5.715309160287632e-01, -4.892811486838007e-01, -3.453559323773929e-01, -1.952095477465681e-01, -8.486421152646519e-02, -2.704948603586857e-02, -5.601093296530086e-03, -6.196575456954947e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_x_ktbm_1_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_1", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.964977330215167e+00, -5.834203589275674e+00, -5.650849918942558e+00, -5.396679692036027e+00, -5.050124933023501e+00, -4.589026707138436e+00, -3.998112784953668e+00, -3.286642730900912e+00, -2.522164567956534e+00, -1.810934304990372e+00, -1.161874499793598e+00, -7.896308763111084e-01, -7.882009674359265e-01, -6.113186859974415e-01, -4.021849952593761e-01, -2.382953493957786e-01, -1.087238077624954e-01, -3.505744148772263e-02, -7.268029316111166e-03, -8.040440015236583e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_1_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_1", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-8.037659936245114e-06, -8.697311766897392e-06, -9.738180798522569e-06, -1.144700725212389e-05, -1.441355197556572e-05, -1.997744224157067e-05, -3.154401301254289e-05, -5.872945168756786e-05, -1.288950434717211e-04, -2.964703152040437e-04, -7.261995708931677e-04, -4.435339378544353e-03, -2.015789818868148e-02, -4.791203035082389e-02, -1.397267930373833e-01, -3.634834972498797e-01, -9.506283316192291e-01, -6.296202226633207e+00, -1.455902160083052e+02, -1.249818306488305e+04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_1_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_1", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([8.167944761471469e-03, 8.325444226367301e-03, 8.555915996239481e-03, 8.895320273516668e-03, 9.398923474991321e-03, 1.015097469265858e-02, 1.126865610158561e-02, 1.282857622789218e-02, 1.424382017007652e-02, 1.198776677716962e-02, 4.776384420511077e-03, 1.988182894765414e-04, 3.202705607032258e-02, 5.137807206621490e-02, 5.584166535809602e-02, 3.132335651124681e-02, 7.395418213574624e-03, 1.556826686838157e-03, 3.217141796968490e-04, 3.793259990592259e-05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_1_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_1", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.553890596247874e-02, -1.630064415524287e-02, -1.745910642633810e-02, -1.926142215368120e-02, -2.215102041576860e-02, -2.695156796321469e-02, -3.513785325621620e-02, -4.832082763228419e-02, -6.043183154246227e-02, -5.213582768986192e-02, -1.150164502344717e-01, -5.106785359214805e-01, -9.312583889514049e-01, -1.399542564047830e+00, -1.671083639170698e+00, -2.296675702507551e+00, -2.765298592793608e+01, -3.248865028904818e+02, -7.723443373907539e+03, -6.313278946860229e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_1_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_1", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([5.579350765917753e-08, 6.387556294234257e-08, 7.750876152591089e-08, 1.021142375674421e-07, 1.509014362803085e-07, 2.606820421446308e-07, 5.490895283359430e-07, 1.402853613967789e-06, 2.867552397859872e-06, -2.617252502326318e-05, -4.954900436473394e-04, -4.400887393727160e-03, 3.284269193629802e-02, 1.406491405639635e-01, -5.095015583568234e-01, -4.287049611384244e+01, -1.423542299006710e+03, -2.231581303536578e+05, -5.503545992311915e+08, -3.544582881446817e+13]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_1_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_1", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.863720038799604e-05, -2.035905419923759e-05, -2.311975553979055e-05, -2.776020712802452e-05, -3.610063299147776e-05, -5.254265172590356e-05, -8.894989145651690e-05, -1.768758360326016e-04, -3.188001273704144e-04, 3.868053592893964e-04, 1.885729889977220e-03, 1.224321563512997e-02, 8.119256820237543e-02, 3.912411671447505e-02, 1.308185497039240e-01, 2.374638534484446e+00, 9.055649155579891e+00, 5.304401935517040e+01, 1.213778879875697e+03, 1.075772353046844e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_1_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_1", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.972237975349904e-14, -3.744321776898726e-14, -5.210792380431617e-14, -8.350988320568101e-14, -1.631692506635874e-13, -4.188233569011820e-13, -1.538548852667061e-12, -8.446935099048872e-12, -4.336994820807287e-11, 2.585805420288055e-09, 2.766546383395062e-07, 1.070291098354458e-05, -4.264536552946504e-04, -4.572003685224588e-03, 9.726771132134268e-02, 8.220311280713135e+01, 7.643466717317245e+04, 7.795430503693390e+08, 2.734050338786960e+14, 1.389939131036408e+22]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_1_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_1", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.664297527600675e-10, 2.014921004510049e-10, 2.651775424916664e-10, 3.933258231853560e-10, 6.920499852131705e-10, 1.551370549450084e-09, 4.875686563257256e-09, 2.402885570216321e-08, 1.978805806072541e-07, 2.273060397416287e-06, 3.125882855709800e-05, 1.203661839021004e-03, 1.341001694539262e-02, 9.979674889392232e-02, 1.977413921975519e+00, 4.719421188189074e+01, 1.222970584885795e+03, 1.203622915572581e+05, 2.171086869991828e+08, 1.321411593570706e+13]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_1_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_1", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.947787975805585e-07, -3.360262120034190e-07, -4.056602900480516e-07, -5.317798109153983e-07, -7.844883334510930e-07, -1.369538026744586e-06, -3.029102870529427e-06, -9.190524515950982e-06, -3.924092613364582e-05, -1.757935622213054e-04, -4.593983716008374e-04, -2.382765573449708e-03, -5.705063955615512e-02, -2.267300046083117e-01, -1.555655018932059e+00, -8.247822227193057e+00, -2.281996831693916e+01, -1.068780463378453e+02, -2.294480064118206e+03, -2.082455499278346e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
