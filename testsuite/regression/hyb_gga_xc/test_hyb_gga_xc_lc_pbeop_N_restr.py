
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_gga_xc_lc_pbeop_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_lc_pbeop", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.170102056843429e+00, -4.087801012577664e+00, -3.972535030458356e+00, -3.812981538183944e+00, -3.595811027119621e+00, -3.307254196202312e+00, -2.936756526354087e+00, -2.483332077848328e+00, -1.963057807221037e+00, -1.409741790101495e+00, -8.719878690705084e-01, -5.245721963542227e-01, -4.345872598597076e-01, -3.319774027592286e-01, -1.928898028956153e-01, -6.721127044794435e-02, -1.071832096128043e-02, -1.569844011081270e-03, -2.935691804167333e-04, -3.274855787717435e-05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_gga_xc_lc_pbeop_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_lc_pbeop", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.284423948832581e+00, -5.170700617337223e+00, -5.011313783317402e+00, -4.790467444046400e+00, -4.489463447359737e+00, -4.088855488162720e+00, -3.573831093712687e+00, -2.945025977207734e+00, -2.237704943993690e+00, -1.546111983619584e+00, -9.845235227967802e-01, -7.044328584892833e-01, -6.064128600945280e-01, -4.618027071056550e-01, -2.813452747984749e-01, -1.162418447129923e-01, -1.983056573735964e-02, -2.292074051821014e-03, -3.918196560380408e-04, -4.364500896513551e-05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_lc_pbeop_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_lc_pbeop", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.438480383007390e-06, -3.710465809021989e-06, -4.138158738137799e-06, -4.836978294667137e-06, -6.042493583835575e-06, -8.286653676570722e-06, -1.292678556453022e-05, -2.395812597056819e-05, -5.506499159196791e-05, -1.599654710894405e-04, -6.474147618525468e-04, -3.119513732988860e-03, -4.885791068893686e-03, -8.136524319164770e-03, -1.371470596937002e-02, 1.722924498944754e-02, 1.237422179893481e-01, 1.972808928108436e-01, 2.397088788371358e-01, 2.666040602132690e-01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_lc_pbeop_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_lc_pbeop", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.195512191603591e-02, -1.249382548648575e-02, -1.331009147257547e-02, -1.457467003229055e-02, -1.659552178733430e-02, -1.996439391110676e-02, -2.589151023215125e-02, -3.690735043523401e-02, -5.729203813398829e-02, -8.509605019887548e-02, -1.529653583511614e-01, -4.833957429768916e-01, -6.104829645918484e-01, -9.378837443838077e-01, -1.833054971301313e+00, -6.350238874222830e+00, -2.031294574318785e+01, -4.174569274341924e+01, -4.683664081533884e+02, -3.760624229209136e+04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_lc_pbeop_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_lc_pbeop", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.079635220444748e-08, 2.366759897426158e-08, 2.847557675177448e-08, 3.706526869191342e-08, 5.386843647342462e-08, 9.109346729442461e-08, 1.880848872236124e-07, 4.904393947662042e-07, 1.441171883318013e-06, -2.428336838227265e-06, -1.781720884870736e-04, 3.901007982378405e-03, 1.012178631161320e-02, 2.175365783044910e-02, -2.994068395136337e-02, 2.673068732307843e+00, 4.399011535663645e+02, 2.412484825588221e+04, 3.352541346072373e+06, 2.761905220412625e+09]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_lc_pbeop_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_lc_pbeop", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([4.370990448008703e-14, 5.540663671639888e-14, 7.786782301040579e-14, 1.268331812025520e-13, 2.549454756494446e-13, 6.905895399868015e-13, 2.846246244726100e-12, 2.099007275743726e-11, 3.380261274012912e-10, 1.432582820458912e-08, 1.712741573600453e-06, 9.996115131070912e-05, 3.506020761808796e-04, 3.063009546770282e-03, 6.406455909917580e-02, -4.304404688668442e+01, -4.224990680529622e+04, -7.301488102653971e+07, -1.218190140296647e+12, -7.786869495661155e+17]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
