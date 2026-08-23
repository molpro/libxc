
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_x_lsrpbe_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_lsrpbe", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.306096870792332e+00, -4.224529196740499e+00, -4.110361798225106e+00, -3.952483330546633e+00, -3.737931850637513e+00, -3.453617352243543e+00, -3.090328316217712e+00, -2.649888552962550e+00, -2.154035797615891e+00, -1.641412585272711e+00, -1.112983976447357e+00, -6.655266112977577e-01, -5.629326654817807e-01, -4.732597670448765e-01, -3.537967700467440e-01, -2.400298940237889e-01, -1.188572117527599e-01, -1.707849723772172e-02, -2.262887480060727e-11, 0.000000000000000e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_x_lsrpbe_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_lsrpbe", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.369111895744910e+00, -5.254155484844800e+00, -5.092924760190959e+00, -4.869275700364202e+00, -4.563914400987542e+00, -4.156327107781124e+00, -3.629720412950584e+00, -2.981166287896372e+00, -2.241790143085014e+00, -1.518794639418118e+00, -9.792156955022193e-01, -7.953303314240748e-01, -7.145875396863566e-01, -5.506607190007934e-01, -3.479310376672130e-01, -2.054392940805745e-01, -1.816064277050495e-01, -6.416436126565826e-02, -1.223520558079233e-09, -0.000000000000000e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_lsrpbe_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_lsrpbe", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.995250420618347e-06, -4.326658618405872e-06, -4.850853285734468e-06, -5.714874014270193e-06, -7.225300878506476e-06, -1.009571255112656e-05, -1.623057330883592e-05, -3.164642986987291e-05, -7.952216447989805e-05, -2.695140133966365e-04, -1.344410332344345e-03, -7.385458164299983e-03, -1.337045823780240e-02, -2.985288165484220e-02, -1.166500106961877e-01, -6.136606636040856e-01, 1.567975538869659e+00, 9.327428714231164e+01, 3.249097397622757e-04, 0.000000000000000e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_lsrpbe_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_lsrpbe", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.249455729322553e-02, -1.308852931882031e-02, -1.399386003496690e-02, -1.540912414251476e-02, -1.770300786797380e-02, -2.161591257494181e-02, -2.877373306579360e-02, -4.303131094580986e-02, -7.289340165009549e-02, -1.179992006656144e-01, -1.825222891506185e-01, -5.933731698470462e-01, -6.877652542701411e-01, -1.254996181422238e+00, -2.761724835107541e+00, 7.386255120270450e+00, 6.844014621863941e+01, -2.066837100216918e+03, -2.161949052791313e-01, -0.000000000000000e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_lsrpbe_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_lsrpbe", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.683578908009725e-08, 3.076351315824683e-08, 3.741656398959165e-08, 4.951204892341242e-08, 7.382786460421661e-08, 1.301425867977142e-07, 2.886608794741000e-07, 8.638200897847361e-07, 3.572201789289453e-06, 1.292322590691266e-05, -5.499008630656558e-05, 1.326544375332794e-02, 4.029377709330238e-02, 1.469858002676547e-01, 9.711731896724006e-01, -7.105124352075477e+01, -8.818172198778875e+03, 3.159922877407203e+06, 5.847400691844710e+04, 0.000000000000000e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_lsrpbe_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_lsrpbe", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.121930988597537e-14, 3.980861706764639e-14, 5.643824521507810e-14, 9.313859978986605e-14, 1.909774001103326e-13, 5.335897155474538e-13, 2.311750355420630e-12, 1.854910716870006e-11, 3.474225096305533e-10, 1.933095705448473e-08, 3.118226398682959e-06, 2.113903007280700e-04, 1.138016172491761e-03, 1.462666565924487e-02, 1.272311124520867e+00, 7.568277702246797e+02, 4.534643521345957e+05, -1.582774519578086e+10, -1.633352115427019e+10, -0.000000000000000e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
