
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_lda_c_rc04_N_2_zk():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_rc04", 2)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-7.832031773967116e-02, -7.821649640725939e-02, -7.806407463718745e-02, -7.783833966475853e-02, -7.749987787173666e-02, -7.698353350793727e-02, -7.617668905779260e-02, -7.487435475810811e-02, -7.268404079228018e-02, -6.883597800104768e-02, -6.180787939060562e-02, -5.181472760332134e-02, -4.879532788556051e-02, -4.536144997493207e-02, -3.764385917454920e-02, -2.597421290917141e-02, -1.323221155820777e-02, -4.328516372187188e-03, -8.236422926498762e-04, -8.312699933660223e-05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_lda_c_rc04_N_2_vrho():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_rc04", 2)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-8.000051382069728e-02, -8.000178491038833e-02, -7.992610651045147e-02, -7.992881541787987e-02, -7.981620158456446e-02, -7.982205039364348e-02, -7.965191699268845e-02, -7.966478492242492e-02, -7.940199968565186e-02, -7.943109123287043e-02, -7.901173378305353e-02, -7.908014961958607e-02, -7.837753176972412e-02, -7.854791526999150e-02, -7.728062401544367e-02, -7.774169936754506e-02, -7.518495741835368e-02, -7.658918405610322e-02, -7.054854703965110e-02, -7.552225092900418e-02, -5.957690216396478e-02, -7.856135595135544e-02, -4.668621413082127e-02, -9.171964800013395e-02, -4.427403034256194e-02, -9.076162136552676e-02, -4.201176129634900e-02, -8.328235313941862e-02, -3.594685815314523e-02, -7.337277238503916e-02, -2.596902208746111e-02, -5.793971441816723e-02, -1.407852045954320e-02, -3.686912879048177e-02, -4.948969796558367e-03, -1.689074072179852e-02, -1.010579507461516e-03, -5.172547491579500e-03, -1.072000155421260e-04, -9.450621843720441e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_lda_c_rc04_N_2_v2rho2():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_rc04", 2)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.848899217198783e-04, -2.982123406168173e-04, 2.849038123215429e-04, 3.023216271483341e-04, -3.167636579560735e-04, 3.023530860141208e-04, 3.292221133595247e-04, -3.454447258987029e-04, 3.292962350622939e-04, 3.720201559201101e-04, -3.912037937514972e-04, 3.722050128386713e-04, 4.431381069399362e-04, -4.675762823137351e-04, 4.436383520330608e-04, 5.688430574210910e-04, -6.035366824003542e-04, 5.703650293263050e-04, 8.111869061745403e-04, -8.689235627346544e-04, 8.166634844997120e-04, 1.337575789436650e-03, -1.459274211689954e-03, 1.362612046098120e-03, 2.668511377715013e-03, -3.034635523797622e-03, 2.828724226288458e-03, 6.497319266420526e-03, -8.333233431119457e-03, 8.088113399914961e-03, 1.458518646125551e-02, -2.883437414192288e-02, 3.699101474262656e-02, 1.460548843636205e-02, -7.279974775967193e-02, 1.802725161757159e-01, 1.800211004996070e-02, -1.076764709322684e-01, 2.841570222800761e-01, 3.118383780608008e-02, -1.963344574245257e-01, 4.697456644442380e-01, 5.904293470897911e-02, -5.655318882255108e-01, 1.347695671273483e+00, 5.301159409509218e-02, -2.662087453842156e+00, 7.026791906066258e+00, -1.234625461518197e+00, -2.116940296371272e+01, 7.590792284800652e+01, -2.936433377014383e+01, -3.141567076694919e+02, 2.243903606476655e+03, -9.449655620091023e+02, -1.146251698008670e+04, 2.653471361971946e+05, -8.581958563923907e+04, -1.609930702272397e+06, 1.842956184750781e+08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
