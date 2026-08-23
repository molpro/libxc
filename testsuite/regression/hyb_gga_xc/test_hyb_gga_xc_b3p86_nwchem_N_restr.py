
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_gga_xc_b3p86_nwchem_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_b3p86_nwchem", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.547389294594737e+00, -3.480885288641571e+00, -3.387731824519650e+00, -3.258764842733433e+00, -3.083188629296429e+00, -2.849849344731758e+00, -2.550247754493470e+00, -2.183957278703749e+00, -1.765786904440704e+00, -1.328432668843516e+00, -9.005325403737956e-01, -6.018429006436020e-01, -5.267003474504173e-01, -4.400357507260862e-01, -3.227646685872037e-01, -2.082885270274756e-01, -1.269863038849726e-01, -8.644046533747954e-02, -5.032755276249411e-02, -3.059254138022979e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_gga_xc_b3p86_nwchem_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_b3p86_nwchem", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.468840346216497e+00, -4.376925132877754e+00, -4.248048166205856e+00, -4.069356879139775e+00, -3.825542172876405e+00, -3.500431565061001e+00, -3.080959974571669e+00, -2.564861219618403e+00, -1.973487915290612e+00, -1.372233190258406e+00, -9.062837155549379e-01, -7.516105147288340e-01, -6.729986478817275e-01, -5.456337144872682e-01, -3.799960409426774e-01, -2.214241804328022e-01, -9.297717946854803e-02, -4.531578422775839e-02, -2.170458192111686e-02, -6.560707411101471e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_b3p86_nwchem_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_b3p86_nwchem", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.481687807000273e-06, -2.684284135875521e-06, -3.003848045874212e-06, -3.528416474003353e-06, -4.439804279674952e-06, -6.155868729084908e-06, -9.773802987671055e-06, -1.869717708395709e-05, -4.593466894462200e-05, -1.558005112392139e-04, -7.574178588823380e-04, -2.557168771534849e-03, -3.827558514420027e-03, -9.104842106513279e-03, -3.530313632086440e-02, -2.552672404442287e-01, -4.750113896147384e+00, -1.514440883758868e+02, -1.216170574250957e+04, -7.225559591112937e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_b3p86_nwchem_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_b3p86_nwchem", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-9.823481560314701e-03, -1.027617316824297e-02, -1.096405680312471e-02, -1.203462251324168e-02, -1.375876210606362e-02, -1.667416196492190e-02, -2.195451241796196e-02, -3.246586550674165e-02, -5.610882834890390e-02, -1.171933030164402e-01, -2.939261118580208e-01, -4.340918998927186e-01, -5.284971344744425e-01, -8.947445242382361e-01, -2.191747622994042e+00, -9.385779753718408e+00, -8.411682771886724e+01, 7.998344571301685e+02, 6.207155648681628e+03, 6.154367737272078e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_b3p86_nwchem_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_b3p86_nwchem", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.909476293615989e-08, 2.177917253773180e-08, 2.629646897505297e-08, 3.443265301894990e-08, 5.057614153886943e-08, 8.731426750994619e-08, 1.886643330499132e-07, 5.535313283394126e-07, 2.436936450374997e-06, 1.836788390596357e-05, 3.366030181982129e-04, 5.697139725090656e-03, 1.414859931757416e-02, 5.482400867597810e-02, 5.744078284708549e-01, 2.401456765718867e+01, 4.236737373332210e+03, -2.631513809260895e+06, -7.702444046207114e+09, -2.455467461863329e+15]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_b3p86_nwchem_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_b3p86_nwchem", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.851336110586064e-14, -2.058565120746870e-14, -2.348532488916387e-14, -2.668244204383284e-14, -2.460865873885425e-14, 2.514531287006040e-14, 5.022431526126959e-13, 6.324042962339535e-12, 1.303159174879722e-10, 6.123760995847717e-09, 6.739400090348285e-07, -6.479879514647381e-05, -1.104767575048738e-03, -1.749050639344055e-03, 3.191811245790399e-02, 7.651630092001312e+00, 1.306801164495676e+05, 2.015066834347820e+10, 1.757145187898871e+16, 5.795234463890628e+24]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
