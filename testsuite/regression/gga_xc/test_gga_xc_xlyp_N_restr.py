
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_xc_xlyp_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_xlyp", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.394988333533752e+00, -4.313243780922097e+00, -4.198782154393441e+00, -4.040394749058390e+00, -3.824923322756955e+00, -3.538863919399107e+00, -3.172093557686962e+00, -2.724383451929153e+00, -2.213228691671704e+00, -1.673504988954083e+00, -1.130342527767652e+00, -7.118831975301637e-01, -6.069686877162693e-01, -5.115352679562545e-01, -3.760764890505977e-01, -2.375525585716057e-01, -1.302497830695695e-01, -7.193171097585915e-02, -4.283016720384181e-02, -2.936045188148061e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_xc_xlyp_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_xlyp", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.434987727173395e+00, -5.321271884296251e+00, -5.161910450682866e+00, -4.941127678534210e+00, -4.640259945326128e+00, -4.239900697437722e+00, -3.725190034815552e+00, -3.096141864302336e+00, -2.384967875832461e+00, -1.679748726248776e+00, -1.116673561760572e+00, -8.546892447327941e-01, -7.639180658275252e-01, -6.066717448625027e-01, -4.148742382645642e-01, -2.529447725057810e-01, -1.494775940161227e-01, -4.920490718826467e-02, -1.246402942759773e-02, -4.878509004054249e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_xc_xlyp_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_xlyp", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.357526189969927e-06, -4.696661173626580e-06, -5.229316331763836e-06, -6.098266120711169e-06, -7.594329069361674e-06, -1.037372512742478e-05, -1.611660259547805e-05, -2.984834601222572e-05, -6.973209112840283e-05, -2.184073297350897e-04, -1.027835289801538e-03, -6.896719608859436e-03, -1.381186373973855e-02, -2.576658755415534e-02, -7.876703436945112e-02, -3.276557169884717e-01, -7.539895977879985e-01, -1.003877872458908e+02, -1.215325647382458e+04, -7.245598090645297e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_xc_xlyp_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_xlyp", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.202289004949987e-02, -1.255863523526482e-02, -1.336964383963928e-02, -1.462449481479847e-02, -1.662682513238021e-02, -1.996115266339698e-02, -2.583916436578016e-02, -3.694262159977429e-02, -5.914757241591099e-02, -1.007489107215113e-01, -1.865307868368893e-01, -5.311112076202427e-01, -6.731082346885453e-01, -1.074756488021974e+00, -1.918562929132400e+00, 4.590922768866026e-01, 8.769555970843118e+01, -1.193434542439309e+03, 1.057016622309137e+04, 7.432307572039654e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_xc_xlyp_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_xlyp", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.175478975893444e-08, 2.465670268725442e-08, 2.949377978705810e-08, 3.808167774444864e-08, 5.474648385514779e-08, 9.133403829486560e-08, 1.862121197244618e-07, 4.891738521206889e-07, 1.656602793436743e-06, 4.117050010688336e-06, -7.748556274021308e-05, 7.468818530600316e-03, 3.049426669812860e-02, 6.628950021050790e-02, -2.347902941965196e-02, -4.155411386788018e+01, -1.048569206616306e+04, 1.643250533280310e+06, -6.829541106214453e+09, -2.461949605559546e+15]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_xc_xlyp_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_xlyp", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.135276950981802e-13, 1.416337076443806e-13, 1.945357738295813e-13, 3.065583916870767e-13, 5.875127589549180e-13, 1.485760283754869e-12, 5.549618924786193e-12, 3.567033752086156e-11, 4.826937313212697e-10, 1.779545544791684e-08, 2.392160397214547e-06, 5.626512093700433e-04, 4.934769564709320e-03, 3.332703229756626e-02, 1.441871051513137e+00, 4.276748882205395e+02, 9.363333655837177e+05, 6.527185032638439e+09, 1.730645762025803e+16, 5.811237014856496e+24]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
