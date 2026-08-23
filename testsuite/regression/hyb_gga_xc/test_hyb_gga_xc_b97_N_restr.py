
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_gga_xc_b97_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_b97", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.548802512406987e+00, -3.481413519399673e+00, -3.387025338312033e+00, -3.256369064206165e+00, -3.078564428791863e+00, -2.842498839871859e+00, -2.540131532929011e+00, -2.172611893363692e+00, -1.758551048986108e+00, -1.334218716735508e+00, -9.083100752146575e-01, -5.816212996879526e-01, -5.060228269895619e-01, -4.190023912116451e-01, -3.062825260737218e-01, -1.976162681662200e-01, -1.011635253387173e-01, -3.134651231422624e-02, -5.595360495142893e-03, -5.574802107710074e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_gga_xc_b97_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_b97", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.512102438408676e+00, -4.419104456992452e+00, -4.288477960817647e+00, -4.106880700600676e+00, -3.858112339782070e+00, -3.524402791989016e+00, -3.090003535669527e+00, -2.548961020832711e+00, -1.921227995171444e+00, -1.289671771577788e+00, -8.368044410626362e-01, -7.296453886985680e-01, -6.520070029781436e-01, -5.195438212108910e-01, -3.397067896855711e-01, -1.956014240097912e-01, -1.137805053137091e-01, -4.203486539027451e-02, -7.600272191921545e-03, -7.479487868208026e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_b97_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_b97", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.098157741246512e-06, -2.273950327624825e-06, -2.554742603619644e-06, -3.024334853871437e-06, -3.863039799168285e-06, -5.507479303667128e-06, -9.180358414095813e-06, -1.896918555042835e-05, -5.170020289777644e-05, -1.931686269286180e-04, -9.804968133843286e-04, -2.811858381940537e-03, -4.249508743200766e-03, -1.132094077321485e-02, -5.972689734387816e-02, -3.606349057809142e-01, -1.619527759474032e+00, -2.239384242577972e+00, -9.170861576028668e-01, 2.720582061937481e-01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_b97_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_b97", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-9.693169762209861e-03, -1.019132097158856e-02, -1.095594700013654e-02, -1.216296392708188e-02, -1.414561723105266e-02, -1.758941120330594e-02, -2.405021192802888e-02, -3.746473724103764e-02, -6.852297029640335e-02, -1.397413449839125e-01, -2.964256461090966e-01, -5.043742001664675e-01, -4.457854769880667e-01, -1.120474108198209e+00, -2.578299332413829e+00, -3.845751294888183e+00, 1.631249087670479e+01, -3.650448000058315e+02, -9.567148018284121e+03, -6.641525888840216e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_b97_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_b97", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.594004129532607e-08, 1.885122398440502e-08, 2.390942530444295e-08, 3.341931701041115e-08, 5.337307517676196e-08, 1.020722314486104e-07, 2.480572633481150e-07, 8.238487981928291e-07, 4.028494658815828e-06, 2.870807132445568e-05, 3.670281626361488e-04, 1.122504958431562e-02, -1.703814638438972e-02, 1.404714288788802e-01, 1.011996683653633e+00, -4.548944622727543e+00, -3.688819363682719e+03, -2.675352195130030e+05, -1.377403163787213e+07, 2.559834563203169e+09]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_b97_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_b97", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-8.317446187798913e-15, -1.583254520573732e-14, -3.117963926020888e-14, -6.642354463957909e-14, -1.604268615690263e-13, -4.627249699579592e-13, -1.672249734187743e-12, -7.357813620220277e-12, -4.060436122500135e-13, 5.584439075775775e-09, 1.114498362129801e-06, -4.663936380861506e-04, 1.075590027039787e-02, -2.880116806931134e-02, 8.530885212905359e-02, 2.212116654124178e+02, 3.794022497818890e+05, 7.799971028630397e+08, 4.630402044389176e+12, -7.948156173406524e+17]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
