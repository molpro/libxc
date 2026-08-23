
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_gga_x_s12h_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_x_s12h", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.229098093323459e+00, -3.166374262313944e+00, -3.078740278436975e+00, -2.957905303386990e+00, -2.794482837592211e+00, -2.579678525183218e+00, -2.308870663810833e+00, -1.986512653465391e+00, -1.626625751307114e+00, -1.241905435324827e+00, -8.379835567499664e-01, -4.970533711924032e-01, -4.240601665510905e-01, -3.537657725382162e-01, -2.678991991531427e-01, -1.766920040924825e-01, -9.049510425830844e-02, -3.070015233560566e-02, -6.406827070388720e-03, -7.086659698868615e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_gga_x_s12h_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_x_s12h", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.137191015367877e+00, -4.042869380227601e+00, -3.909923575678145e+00, -3.724246421443389e+00, -3.468525926621575e+00, -3.124394355377856e+00, -2.680958480345219e+00, -2.158317859094044e+00, -1.633017594247426e+00, -1.183016007987599e+00, -7.932376961762068e-01, -5.946878516014401e-01, -5.546599710383592e-01, -4.043629778106507e-01, -2.603716923482933e-01, -1.720202080270070e-01, -1.065330786817362e-01, -4.026001381095690e-02, -8.535780468562132e-03, -9.448784986101437e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_x_s12h_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_x_s12h", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.805538146604453e-06, -2.045466775356991e-06, -2.441505844052482e-06, -3.132358242543570e-06, -4.429013422000307e-06, -7.094681577212580e-06, -1.314857329727517e-05, -2.811196452557235e-05, -6.760617859974414e-05, -1.902811352008853e-04, -8.631537968453115e-04, -5.460544717748525e-03, -3.995080770589395e-03, -2.501280949997548e-02, -9.123652694581499e-02, -3.403986280419782e-01, -9.576630271919672e-01, -1.517703375271650e+00, -1.812108594445885e+00, -2.000436464247179e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_x_s12h_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_x_s12h", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.177373472173083e-02, -1.251751161684275e-02, -1.366480865550453e-02, -1.547576852623161e-02, -1.839696919657760e-02, -2.311209268672081e-02, -3.010854943920192e-02, -3.716054892700666e-02, -3.589528235623078e-02, -1.434206247756653e-02, 2.541897166555573e-02, -6.358438604829423e-01, -5.766836726866361e-01, -1.276880150393977e+00, -8.323581082575093e-01, 3.914102439865010e+00, 9.808530135773044e+00, -3.354466605279375e+02, -9.868737534216398e+03, -8.156907057625066e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_x_s12h_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_x_s12h", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([4.370462403270080e-08, 5.163253103818502e-08, 6.529203861451796e-08, 9.049872564121219e-08, 1.411421818789810e-07, 2.523174523599570e-07, 5.061192345800853e-07, 9.697392855683088e-07, 4.315185151265317e-07, -2.114838943129741e-05, -5.060568657615940e-04, 2.533876428632023e-02, 4.719255594429955e-02, 2.399405856388710e-01, -4.363176444007824e-01, -4.733457122415053e+01, -3.116181185835101e+03, -1.836873436402583e+05, -2.534711601850605e+07, -2.072530354042341e+10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_x_s12h_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_x_s12h", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.247060882242734e-13, -4.050885699046307e-13, -5.531056033390627e-13, -8.526124086717726e-13, -1.532501999783756e-12, -3.246024386192740e-12, -7.132666658892093e-12, 4.874364180613705e-12, 6.240978779084745e-10, 2.582976913572935e-08, 3.255822197493193e-06, -1.089943312397514e-03, -1.271963738355039e-02, -3.113356824789018e-02, 2.121983589483829e+00, 4.622359605365531e+02, 2.993848497820541e+05, 5.555965387256613e+08, 9.204409919183484e+12, 5.842760652130399e+18]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
