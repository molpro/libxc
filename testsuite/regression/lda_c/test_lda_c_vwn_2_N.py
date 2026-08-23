
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_lda_c_vwn_2_N_2_zk():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_vwn_2", 2)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.185824110985881e-01, -1.179948578928934e-01, -1.171517400878819e-01, -1.159432736515825e-01, -1.142140701725737e-01, -1.117459498899519e-01, -1.082363239116926e-01, -1.032743270821437e-01, -9.632887045519051e-02, -8.682050309454950e-02, -7.433691471772023e-02, -6.096135396566790e-02, -5.706913625606713e-02, -5.287306356279194e-02, -4.437065877663218e-02, -3.247083085615147e-02, -1.925321415081073e-02, -8.238019905181136e-03, -2.230212031740047e-03, -3.134819531845416e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_lda_c_vwn_2_N_2_vrho():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_vwn_2", 2)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.281835878963110e-01, -1.281854061318648e-01, -1.275854979999261e-01, -1.275893611687606e-01, -1.267263127998715e-01, -1.267346174277078e-01, -1.254926675417479e-01, -1.255108248304733e-01, -1.237223696229587e-01, -1.237630560922186e-01, -1.211829853414317e-01, -1.212774735257419e-01, -1.175381885874673e-01, -1.177693924731159e-01, -1.122846303341219e-01, -1.128953131558714e-01, -1.045928126353211e-01, -1.063939941359222e-01, -9.280204761113112e-02, -9.893939987335718e-02, -7.395190352041803e-02, -9.650945575116635e-02, -5.583040286118472e-02, -1.093913209121988e-01, -5.216575854537687e-02, -1.075929323125821e-01, -4.875185732407991e-02, -9.780635845891963e-02, -4.121826426432323e-02, -8.659998107952084e-02, -3.065009531265961e-02, -7.209732311945810e-02, -1.904600118391921e-02, -5.250106085402667e-02, -9.057203341506439e-03, -2.767603756845385e-02, -2.791919986580487e-03, -5.847691322463971e-03, -4.149753024268812e-04, 5.186261095286490e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_lda_c_vwn_2_N_2_v2rho2():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_vwn_2", 2)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.625658999279540e-04, -4.715356713536182e-04, 3.625847570314404e-04, 3.835552400505741e-04, -4.993225004759685e-04, 3.835978216218626e-04, 4.158309446835692e-04, -5.421200737367639e-04, 4.159308530186960e-04, 4.669216502805660e-04, -6.100318703313368e-04, 4.671693337114556e-04, 5.512132910150136e-04, -7.224990137322798e-04, 5.518779031080978e-04, 6.987113631065514e-04, -9.204981470827277e-04, 7.007095266230268e-04, 9.791342579408831e-04, -1.300889197496753e-03, 9.862071434653963e-04, 1.576863086134766e-03, -2.128243818359132e-03, 1.608490265966349e-03, 3.051475847464362e-03, -4.267879462441741e-03, 3.248268514679899e-03, 7.158174357252009e-03, -1.116470326612688e-02, 9.051891323704047e-03, 1.519276383190425e-02, -3.642295968096059e-02, 4.113423027740253e-02, 1.591495576743317e-02, -9.559302252549347e-02, 2.261796451209584e-01, 2.037254724163598e-02, -1.410895495963849e-01, 3.643173570880001e-01, 3.650784725269726e-02, -2.483351549899479e-01, 5.975153002673527e-01, 8.264411823543649e-02, -6.992829229023547e-01, 1.782944320130832e+00, 2.061342992535625e-01, -3.283019554144584e+00, 1.001338970216920e+01, -3.483251628476848e-01, -2.646960812900180e+01, 1.079172050990451e+02, -4.118697154582826e+01, -3.664966445823407e+02, 1.905048579017292e+03, -2.462838616550596e+03, -8.566824908393619e+03, -3.910337352084840e+04, -3.308407622567355e+05, 9.095940426068267e+04, -4.395228199912852e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
