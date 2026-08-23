
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_lda_c_vbh_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_vbh", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.330587117484984e-01, -1.325472982273819e-01, -1.318126466274809e-01, -1.307579909205563e-01, -1.292453901069329e-01, -1.270790491259935e-01, -1.239827964554083e-01, -1.195714245480798e-01, -1.133258488602533e-01, -1.046724528257119e-01, -9.398111473353570e-02, -8.621410217247334e-02, -8.290108985862162e-02, -7.764169914365489e-02, -6.847417092976513e-02, -5.512321498090968e-02, -3.785755912419964e-02, -1.906361451294447e-02, -5.365337351283049e-03, -6.563410567410663e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_lda_c_vbh_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_vbh", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.414128201490593e-01, -1.409004673720745e-01, -1.401644328326876e-01, -1.391077202162123e-01, -1.375920155103762e-01, -1.354208930634248e-01, -1.323170550615720e-01, -1.278931404151565e-01, -1.216256221810592e-01, -1.129313523509104e-01, -1.021659473356551e-01, -9.432192132935474e-02, -9.096823668579507e-02, -8.563243892325048e-02, -7.628792218022476e-02, -6.253588104541907e-02, -4.432782785572574e-02, -2.347348050580690e-02, -6.967231419157503e-03, -8.721148655684278e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_lda_c_vbh_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_vbh", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.673321841264322e-05, -4.967989437953676e-05, -5.424145275303234e-05, -6.153307305431615e-05, -7.373772141590990e-05, -9.555961587330151e-05, -1.384454320605182e-04, -2.348993381377382e-04, -4.971269234984715e-04, -1.408874708906145e-03, -5.137805878156930e-03, -1.324174945541352e-02, -1.987655895267164e-02, -3.801246092178655e-02, -1.193020732504988e-01, -6.612396249381253e-01, -7.080536311350770e+00, -1.581685589933904e+02, -7.103989824843170e+03, -7.400858863582624e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
