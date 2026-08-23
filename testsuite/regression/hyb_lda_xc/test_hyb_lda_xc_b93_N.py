
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_lda_xc_b93_N_2_zk():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_lda_xc_b93", 2)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.140548690090330e+00, -2.098207402647432e+00, -2.038858068003864e+00, -1.956605551627986e+00, -1.844446935162116e+00, -1.695015501874170e+00, -1.502390099050538e+00, -1.265457307187827e+00, -9.930070031993601e-01, -7.106691939657661e-01, -4.742687413457599e-01, -3.654235845123922e-01, -3.230905689050440e-01, -2.622456547905719e-01, -1.837004216416993e-01, -1.082634463684210e-01, -5.139021420471432e-02, -1.809996097283310e-02, -4.147103334946015e-03, -5.005230678206201e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_lda_xc_b93_N_2_vrho():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_lda_xc_b93", 2)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.839213755856424e+00, -2.839192132505441e+00, -2.782863668623146e+00, -2.782818486704055e+00, -2.703889625917599e+00, -2.703794799835444e+00, -2.594463532183443e+00, -2.594263215285443e+00, -2.445305135264426e+00, -2.444877863189898e+00, -2.246700099674494e+00, -2.245775404526662e+00, -1.990975115556693e+00, -1.988929157183785e+00, -1.677145642610527e+00, -1.672462415459631e+00, -1.318175034146097e+00, -1.306891226500832e+00, -9.513436982366035e-01, -9.222770476068987e-01, -6.534944794943489e-01, -5.780589870772374e-01, -5.115478166370353e-01, -3.803408416527985e-01, -4.510057420152966e-01, -3.309947620120584e-01, -3.647125676918420e-01, -2.745865173808361e-01, -2.534075750586685e-01, -1.930242411354269e-01, -1.472523950418108e-01, -1.143879852734079e-01, -6.860531412650726e-02, -5.651132915005753e-02, -2.383626768848984e-02, -2.166399699473837e-02, -5.459786670377301e-03, -5.272902505242788e-03, -6.632753464520818e-04, -5.898817056262536e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_lda_xc_b93_N_2_v2rho2():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_lda_xc_b93", 2)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.015285270331627e-02, -2.332738647938709e-04, -1.015301108138224e-02, -1.057282351926058e-02, -2.470016597544935e-04, -1.057317525141115e-02, -1.120663906608848e-02, -2.681436967006964e-04, -1.120744483345417e-02, -1.218337831521262e-02, -3.016885081778898e-04, -1.218530853241312e-02, -1.373424465201627e-02, -3.572329723774618e-04, -1.373917550017783e-02, -1.630403185949023e-02, -4.550000394878667e-04, -1.631784911517875e-02, -2.082823473261904e-02, -6.427821912504471e-04, -2.087246783420759e-02, -2.950052539915875e-02, -1.051109929145720e-03, -2.967196149673565e-02, -4.814107790722684e-02, -2.106997742577937e-03, -4.901243463196939e-02, -9.360351149001785e-02, -5.512401624332891e-03, -9.993977721033853e-02, -2.017609411769490e-01, -1.800793870685515e-02, -2.628263207378774e-01, -3.323159531872447e-01, -4.713222374432352e-02, -6.369089128882248e-01, -4.306226942211867e-01, -6.949557311081772e-02, -8.531401055912573e-01, -6.688130020389362e-01, -1.224347491679582e-01, -1.263251683762584e+00, -1.426965542807165e+00, -3.444759468242997e-01, -2.663898757091770e+00, -4.469908275702502e+00, -1.606203671494536e+00, -8.127169700382895e+00, -2.298553962068991e+01, -1.275610922696772e+01, -3.699499714531586e+01, -2.331500568760486e+02, -1.840921407223062e+02, -2.886930719752129e+02, -6.018972826917751e+03, -5.723268691542396e+03, -9.845693265641137e+03, -5.561778832585644e+05, -5.041185564111635e+05, -3.620139046237718e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
