
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_mgga_xc_coach_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_coach", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.578315458411016e+00, -3.493427728042797e+00, -3.375337408952715e+00, -3.213687027313587e+00, -2.997559801390720e+00, -2.717737664318304e+00, -2.369906614174875e+00, -1.969995043891121e+00, -1.610001184196608e+00, -1.217540862343996e+00, -6.898816363264774e-01, -4.276505503820724e-01, -3.682797156450798e-01, -2.905262385138725e-01, -1.898887086218198e-01, -7.974357968635372e-02, -1.679305966101663e-02, -1.197068726768613e-02, -1.502251343577122e-03, -6.864793542067101e-05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_mgga_xc_coach_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_coach", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-9.496252700497221e-01, -8.899278992587631e-01, -8.175579161993880e-01, -7.441999421879466e-01, -7.090057789370771e-01, -8.107301673841796e-01, -1.214317646908971e+00, -1.885026884664456e+00, -1.865832533670725e+00, -9.519938902194431e-01, -8.349447584480635e-01, -6.277661440593608e-01, -4.934310957058394e-01, -3.757571864751789e-01, -2.461082056254818e-01, -1.055782472194732e-01, -3.509381714145409e-02, -1.246663131579503e-02, -1.456920252100868e-03, -8.071922848021734e-05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_coach_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_coach", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.218047293259228e-04, -1.274308845090221e-04, -1.355289924942609e-04, -1.469640832868519e-04, -1.621425464314982e-04, -1.781732629208113e-04, -1.772972888629559e-04, -9.449270271405606e-05, 7.504815435082753e-05, -5.858996847549961e-04, -1.199783931370171e-03, 1.242462788172864e-03, -6.993581906273254e-03, -1.326093356517298e-02, -5.897771259484521e-02, -1.925459581114045e-01, 6.741471887385437e+00, -5.125491789203024e+01, -8.217557892914969e+02, -2.165693574378677e+04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_coach_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_coach", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.829719858166733e-01, 1.796171507870904e-01, 1.742580912451706e-01, 1.654916339271909e-01, 1.508625749647787e-01, 1.262084974302601e-01, 8.503258814582738e-02, 2.223678833355971e-02, -2.331913282264940e-02, 1.950562902595498e-02, 1.042508306157392e-02, 2.058140272908250e-03, -9.399138225481568e-04, -6.416505497120095e-04, 1.892079687062083e-02, 1.293922135779389e-02, -6.959034547946885e-02, 1.813758462306412e-02, 2.460581371119163e-03, 9.513398122328979e-05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_coach_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_coach", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.662759004601992e-01, -2.850076900784906e-01, -3.130889477103954e-01, -3.554185908505963e-01, -4.187003946094432e-01, -5.081956106674987e-01, -6.062338651043745e-01, -5.636623690772726e-01, 2.502444948904637e-02, -4.743824803354478e-01, 1.704950838744575e-01, -2.075236093807007e-01, -6.903493675009935e-01, -1.662195641989290e+00, -1.788875557031238e-01, 1.247379810862425e+01, 1.003019302279228e+03, 1.207033859642308e+04, 2.919947640307379e+05, -6.864028336378031e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_coach_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_coach", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([7.158784663432939e-06, 8.208517404302757e-06, 9.962112233100442e-06, 1.306768303596822e-05, 1.899040453234709e-05, 3.122188417297028e-05, 5.719953027787783e-05, 9.443429234910765e-05, -3.265475187955324e-05, 4.226170947744061e-04, -1.557908132153129e-03, 3.373076083944486e-02, 8.851677444486502e-03, 8.226761962607030e-03, 4.887347455659133e+00, -8.246146756901480e+00, -1.904827142295476e+05, -7.532985993638113e+07, -2.152954243272075e+11, 3.782107544396552e+15]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_coach_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_coach", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-9.823896763408954e-03, -1.062870741114046e-02, -1.187135385282878e-02, -1.383260118329791e-02, -1.698141107050750e-02, -2.194001668153872e-02, -2.834848641797216e-02, -2.789484717978425e-02, 5.002423898103595e-03, -1.644830983920375e-02, 7.108163630985120e-03, -5.134037688813347e-02, 7.711604368753350e-02, 5.686454113484513e-01, -3.940530477649183e+00, -1.078742379381670e+01, 1.333895260805896e+03, 1.837933207282924e+04, 4.779687206549842e+05, -1.138877940286725e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_coach_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_coach", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.049117218225153e-10, -2.517018548313830e-10, -3.372245000988043e-10, -5.098339951294014e-10, -9.083276630204851e-10, -2.000211238452077e-09, -5.576706292403895e-09, -1.697069708500742e-08, 1.298048138409736e-08, -2.888673635212616e-07, 1.523317585794151e-05, 5.146779505749023e-04, -2.863686350995950e-03, -1.768329960516744e-01, -1.145217455794189e+01, -1.138617916797090e+03, 3.422368292617059e+07, 4.566833680954967e+11, 1.551548264895299e+17, -2.154832417135018e+24]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_coach_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_coach", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.132820833043545e-07, 3.620786967749026e-07, 4.444705546122924e-07, 5.926790950974046e-07, 8.819148488052609e-07, 1.500471940081421e-06, 2.892488159518804e-06, 5.196493195467939e-06, -1.952069563782216e-06, 1.106689652489705e-05, -1.023973815107536e-04, -3.807030965210332e-03, 7.290143753339973e-03, 3.008707091179504e-01, 4.938933028328610e+00, 1.573686981371226e+02, -2.417991188278662e+05, -1.079224458470360e+08, -3.368565254859589e+11, 6.659806533775111e+15]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_coach_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_coach", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.808378235432228e-04, -5.229391833979958e-04, -5.880770115388198e-04, -6.911421674607483e-04, -8.574104769405274e-04, -1.123602168707296e-03, -1.494199909007659e-03, -1.595434714781595e-03, 2.796203045187591e-04, -3.153836082515637e-04, 9.441999516348358e-04, 8.659098174091065e-03, -3.486298594095086e-02, -7.886809164885387e-01, -7.928772362937303e-01, -1.193855684977251e+01, 1.687315633614937e+03, 2.525010335026478e+04, 7.263279704429464e+05, -2.073946398371968e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
