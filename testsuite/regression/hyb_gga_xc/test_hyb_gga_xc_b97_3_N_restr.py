
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_gga_xc_b97_3_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_b97_3", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.214928486348030e+00, -3.153867837072741e+00, -3.068353517866222e+00, -2.950008139467394e+00, -2.789034645982710e+00, -2.575544726893009e+00, -2.302768724102045e+00, -1.972999564828229e+00, -1.604242368909331e+00, -1.220537941268830e+00, -8.280311458630862e-01, -5.302884587416782e-01, -4.637602528819348e-01, -3.821680986781689e-01, -2.813126032943021e-01, -1.790103596182072e-01, -1.036402644180709e-01, -5.090415055384293e-02, -9.206092873916327e-03, -8.481327521504584e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_gga_xc_b97_3_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_b97_3", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.098113022089073e+00, -4.013332981503242e+00, -3.894079467103591e+00, -3.727911171717010e+00, -3.499425163625643e+00, -3.191089184785259e+00, -2.786315757723877e+00, -2.279120551764550e+00, -1.706752686299908e+00, -1.212674007996148e+00, -8.338891338427993e-01, -6.725079475237490e-01, -5.983165954169933e-01, -4.789303764421716e-01, -2.993360062797608e-01, -2.116442337191997e-01, -2.763016391533184e-02, -5.416878261403269e-02, -1.251554140525594e-02, -1.144236970534912e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_b97_3_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_b97_3", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.755979270454632e-06, -1.912335377114583e-06, -2.165137428359062e-06, -2.595696119412030e-06, -3.385702021688080e-06, -4.994885563667917e-06, -8.765024530934048e-06, -1.922106794287292e-05, -5.289779833754798e-05, -1.628779208781142e-04, -6.988374162057781e-04, -1.903950624193783e-03, -3.125447306817319e-03, -8.229161184183861e-03, -6.650685224278283e-02, -1.342850598873224e-01, -7.851543744414791e+00, -3.834648001572264e+01, -4.523435434456683e+01, -4.427001831005992e+01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_b97_3_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_b97_3", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-9.009178808993016e-03, -9.517138301433768e-03, -1.030707839351931e-02, -1.157659251116704e-02, -1.371065487816546e-02, -1.751203133068466e-02, -2.472107893763604e-02, -3.861497083944556e-02, -5.722100663070448e-02, -1.611061054359960e-02, 8.314192250231275e-02, -5.048291745384678e-01, -3.375648808935773e-01, -1.233869019512700e+00, -2.133106381739753e+00, -2.408899097049238e-01, -7.659357080058261e+01, 1.142408874944985e+03, -1.439183815698754e+04, -1.039441377737077e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_b97_3_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_b97_3", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.702160947236920e-08, 2.051168150658362e-08, 2.670583641460032e-08, 3.867549041264922e-08, 6.462765307582095e-08, 1.300378383155391e-07, 3.280130072581095e-07, 1.038611428473439e-06, 3.117718409094907e-06, -1.995853382126694e-05, -6.572278032403595e-04, 1.403322767546630e-02, -4.078756056391425e-02, 2.092673431560416e-01, 7.372753097908502e-01, -2.602762049311293e+01, 5.009271098886033e+03, -4.104385520673124e+06, -6.335464353789715e+08, -4.598374276130324e+11]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_b97_3_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_b97_3", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.839005521821763e-14, -6.909919431821361e-14, -1.107696932019135e-13, -2.056933423174178e-13, -4.598244605770999e-13, -1.292405924791830e-12, -4.700855616371324e-12, -1.941333077089405e-11, 1.286126907247948e-10, 2.270190591615084e-08, 3.267880899937623e-06, -8.728567870288468e-04, 1.826177363104326e-02, -6.282392331120717e-02, 5.113558648527800e-01, 2.002421541563976e+02, 3.196437918278953e+05, 1.268252266617068e+10, 2.286300614145010e+14, 1.292924078899775e+20]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
