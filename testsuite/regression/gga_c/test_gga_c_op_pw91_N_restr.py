
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_c_op_pw91_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_op_pw91", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.897782769530881e-02, -5.866841072694909e-02, -5.821236696423174e-02, -5.753339697738143e-02, -5.650851896538384e-02, -5.493344778367360e-02, -5.246094901023410e-02, -4.850940948056025e-02, -4.225880129866347e-02, -3.356983516024529e-02, -2.786610794454633e-02, -3.997723538863680e-02, -4.136557008193302e-02, -3.382776254146135e-02, -2.300466534894397e-02, -1.128539840272078e-02, -4.217581548800374e-03, -1.319996531644070e-02, -1.472372529775989e+00, -1.140476979275110e+03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_c_op_pw91_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_op_pw91", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-7.565448573810954e-02, -7.575624291715558e-02, -7.589815261165034e-02, -7.609136369933894e-02, -7.634123166090093e-02, -7.662446015311587e-02, -7.681312631174296e-02, -7.643202433744586e-02, -7.400121669231766e-02, -6.655197971704210e-02, -5.800283984135960e-02, -5.855287075256384e-02, -5.388276002807302e-02, -5.228950576129798e-02, -4.329234354323977e-02, -2.479614600667813e-02, -5.089286863603624e-03, 4.655704286595862e-02, 6.149960796055605e+00, 4.597712914936132e+03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_op_pw91_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_op_pw91", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.644416944792482e-07, 1.796685248295848e-07, 2.039303916457011e-07, 2.443115465992943e-07, 3.157721580913207e-07, 4.534707396264576e-07, 7.513314656473034e-07, 1.500808200099388e-06, 3.773221554508909e-06, 1.251954342122719e-05, 7.453367869975455e-05, 1.135186042734008e-03, 2.742940891807706e-03, 5.115986752692500e-03, 1.553292964294791e-02, 6.009805978170056e-02, -1.312100321987712e-02, -1.442712706260837e+02, -2.208901898231254e+06, -1.293632677401679e+12]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_op_pw91_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_op_pw91", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([6.479963826579861e-05, 6.870801802789261e-05, 7.450226287412396e-05, 8.308684103623273e-05, 9.549775463371095e-05, 1.113603908560035e-04, 1.191025123658362e-04, 3.564303608157207e-05, -6.799690362979361e-04, -5.285438252622629e-03, -2.359374991046535e-02, 1.155610353495742e-03, 2.179717133732934e-03, -1.346472778705086e-02, -2.492624572239255e-01, -2.292860231205298e+00, -2.088841983841566e+01, -7.821291701444238e+03, -1.107324879427216e+08, -5.981073878950521e+13]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_op_pw91_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_op_pw91", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-7.805153330283170e-10, -8.841071714132986e-10, -1.054682692929533e-09, -1.350693275784290e-09, -1.899261345774502e-09, -2.985105589277043e-09, -5.100709910931735e-09, -6.101969652169344e-09, 6.263277818557378e-08, 1.874424753687147e-06, 5.532868012415018e-05, -8.529283477912372e-04, -6.041407181890380e-03, -6.727528850984468e-03, 1.355749363073961e-01, 9.929098518394701e+00, 1.334185163184419e+03, 1.870367549904644e+07, 3.210286642344517e+13, 1.348538566717993e+22]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_op_pw91_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_op_pw91", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-7.747838768910330e-15, -9.837427737488033e-15, -1.385289009030460e-14, -2.260910621885002e-14, -4.549269685975189e-14, -1.229218532199041e-13, -5.006219532591135e-13, -3.571204161053175e-12, -5.362565044363700e-11, -2.116784889407229e-09, -3.410325509592565e-07, -1.561401370055377e-04, -1.501442242078445e-03, -1.080343645532194e-02, -4.479702963599886e-01, -9.264527582279101e+01, -8.918974057261461e+04, -2.862767538453456e+10, -5.932911807324006e+18, -1.906678330312947e+30]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
