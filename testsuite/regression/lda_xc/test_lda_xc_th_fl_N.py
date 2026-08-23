
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_lda_xc_th_fl_N_2_zk():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_xc_th_fl", 2)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.896328581486658e+00, -4.813226089245908e+00, -4.694679439219446e+00, -4.526569237821674e+00, -4.290639188600531e+00, -3.965460395951709e+00, -3.530852020460452e+00, -2.978813617693886e+00, -2.332778616974033e+00, -1.670625435307583e+00, -1.143069257818617e+00, -9.195550455180800e-01, -8.327504412550818e-01, -7.081596371675201e-01, -5.518047227555192e-01, -3.999615908987315e-01, -2.701447353479831e-01, -1.630376371676223e-01, -7.992354835908196e-02, -2.792329802242804e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_lda_xc_th_fl_N_2_vrho():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_xc_th_fl", 2)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.257247081810863e+00, -6.257211358457258e+00, -6.167020165970635e+00, -6.166943260626041e+00, -6.036212419065019e+00, -6.036044499513971e+00, -5.846821927721860e+00, -5.846448724173964e+00, -5.574129597792739e+00, -5.573282304101438e+00, -5.186839285667623e+00, -5.184868214713743e+00, -4.651946754417342e+00, -4.647237049404210e+00, -3.949943413081472e+00, -3.938358195448621e+00, -3.105560125449951e+00, -3.076118024486345e+00, -2.229793680305859e+00, -2.152388475572872e+00, -1.544907067931420e+00, -1.346342046536592e+00, -1.241818427778759e+00, -8.974058331082074e-01, -1.111548316257489e+00, -7.950468152833934e-01, -9.282011028671548e-01, -6.874728183660660e-01, -7.020067356534069e-01, -5.291712996139766e-01, -4.915435685364558e-01, -3.709285960749694e-01, -3.229610424709843e-01, -2.354007139352073e-01, -1.918770546333150e-01, -1.259648083313780e-01, -9.336489589106700e-02, -5.035579184224805e-02, -3.255970169833688e-02, -1.332485338834629e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_lda_xc_th_fl_N_2_v2rho2():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_xc_th_fl", 2)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.638776746485261e-02, 1.442550547944625e-132, -1.638823026627551e-02, -1.757564045293835e-02, -3.606478620880277e-132, -1.757666956247186e-02, -1.936959645225898e-02, -9.714802588212454e-133, -1.937195741588209e-02, -2.213533550914861e-02, 1.466238751977350e-132, -2.214099894746427e-02, -2.652467752268866e-02, 4.550805411758373e-132, -2.653915400084477e-02, -3.377811481967609e-02, 3.224486073263785e-132, -3.381861780713373e-02, -4.645251387230875e-02, -4.294276603141720e-132, -4.658135351194057e-02, -7.034348343882540e-02, -1.987014527052943e-132, -7.083522241900492e-02, -1.200367941723081e-01, 8.228837952733375e-133, -1.224640856052703e-01, -2.345528174322461e-01, -2.112134253561920e-131, -2.514587645788525e-01, -4.848003644954596e-01, -8.339444629720640e-132, -6.422786573266059e-01, -7.612576573541886e-01, -2.078880875072182e-131, -1.592713533042636e+00, -9.682957626357842e-01, -1.001933490631990e-130, -2.165745159325740e+00, -1.467388569675952e+00, 3.101256306596079e-131, -3.234375560444285e+00, -3.045514678700620e+00, -2.598453221917052e-130, -7.464995440612772e+00, -9.755438212099294e+00, 8.717726114745340e-131, -3.132571818326347e+01, -6.034293567673333e+01, -1.427352763436507e-129, -3.131079766783209e+02, -9.654772160459987e+02, -8.116061227096695e-128, -1.006475703163316e+04, -5.215943963111328e+04, -1.892292913802585e-125, -1.417285631295610e+06, -1.377250096182669e+07, -3.096468879737357e-123, -1.330476854680307e+09]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
