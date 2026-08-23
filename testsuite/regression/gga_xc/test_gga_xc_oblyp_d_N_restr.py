
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_xc_oblyp_d_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_oblyp_d", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.380242607091601e+00, -4.298260667301580e+00, -4.183457399162668e+00, -4.024578263255116e+00, -3.808399349514089e+00, -3.521324484768248e+00, -3.153110854244765e+00, -2.703422212213047e+00, -2.189909495678183e+00, -1.649005808502815e+00, -1.111444177101672e+00, -7.092125065317721e-01, -6.066948961219215e-01, -5.090981518888251e-01, -3.713234532278152e-01, -2.304403057905484e-01, -1.253001544841202e-01, -9.223246276154680e-02, -5.932898240525027e-02, -4.067370120022128e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_xc_oblyp_d_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_oblyp_d", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.454611667074357e+00, -5.340966420373225e+00, -5.181695300939460e+00, -4.961018374414806e+00, -4.660250476577637e+00, -4.259917750946729e+00, -3.744974458319842e+00, -3.114942382272172e+00, -2.400802367890101e+00, -1.688559636479279e+00, -1.121012050207907e+00, -8.604837205578003e-01, -7.677334859661862e-01, -6.115823700491214e-01, -4.195795960731950e-01, -2.550193535757591e-01, -1.342894570463585e-01, -4.360558347221608e-02, -1.709767791600529e-02, -6.767090508099850e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_xc_oblyp_d_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_oblyp_d", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.928031413199192e-06, -4.234795461533006e-06, -4.716799042424759e-06, -5.503582341641862e-06, -6.859386511757652e-06, -9.381660877523522e-06, -1.460456923699151e-05, -2.713759362014544e-05, -6.376371646166244e-05, -2.016909489990417e-04, -9.497840903571397e-04, -6.130340391090495e-03, -1.218050575803732e-02, -2.271382528524661e-02, -6.860633926215581e-02, -2.700840705197159e-01, -1.261812584911004e+00, -1.680941135718180e+02, -1.688119122734439e+04, -1.003564161318792e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_xc_oblyp_d_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_oblyp_d", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.189469343609158e-02, -1.242426002713060e-02, -1.322619025413488e-02, -1.446770731405338e-02, -1.645078486583083e-02, -1.975949093781508e-02, -2.561596322247754e-02, -3.678285304856078e-02, -5.969408066288352e-02, -1.065997765113423e-01, -2.091831023175774e-01, -5.244003376803846e-01, -6.657771661165254e-01, -1.060323161465436e+00, -1.924541635306618e+00, -5.348985192199489e-01, 3.443582510651545e+01, 5.307567982864880e+01, 1.727699271050427e+04, 1.029044230260720e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_xc_oblyp_d_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_oblyp_d", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.004392360185248e-08, 2.273959082144847e-08, 2.724007818966390e-08, 3.524988175978697e-08, 5.085267420252441e-08, 8.532734627546618e-08, 1.757591911334577e-07, 4.715836219636619e-07, 1.694541185074153e-06, 6.368806472679495e-06, -1.694696322696956e-05, 6.754965545741818e-03, 2.701345492441180e-02, 5.895285854540857e-02, -3.010214402516653e-02, -3.611886127070410e+01, -6.773593125219856e+03, -1.035415819887729e+06, -1.012839316305378e+10, -3.411020349581868e+15]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_xc_oblyp_d_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_oblyp_d", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([9.748015811047853e-14, 1.216429906192339e-13, 1.671358068642695e-13, 2.635093350376539e-13, 5.053650845979379e-13, 1.279301334845264e-12, 4.785097410783423e-12, 3.080865130268299e-11, 4.173491448697092e-10, 1.533315223211893e-08, 2.050929485741555e-06, 4.846783554519337e-04, 4.223195526664112e-03, 2.874874034660694e-02, 1.245716340793178e+00, 3.583153850728017e+02, 7.463214521628007e+05, 1.998928318999335e+10, 2.421391307253097e+16, 8.049177770020587e+24]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
