
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_lda_xc_lda0_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_lda_xc_lda0", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.210823035036796e+00, -3.147311103531047e+00, -3.058287100007607e+00, -2.934908318128215e+00, -2.766670357634215e+00, -2.542523021684739e+00, -2.253583861530352e+00, -1.898177849866231e+00, -1.489449201971232e+00, -1.065414359567434e+00, -7.051206914698487e-01, -5.226240541241082e-01, -4.599068717595507e-01, -3.753023611486538e-01, -2.627471181561933e-01, -1.545212922067024e-01, -7.369434015033013e-02, -2.642663365065473e-02, -6.166800057435567e-03, -7.450386702311921e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_lda_xc_lda0_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_lda_xc_lda0", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.258804416336131e+00, -4.174261616783967e+00, -4.055763320624463e+00, -3.891545066702812e+00, -3.667637278365631e+00, -3.369356779238751e+00, -2.984929044269329e+00, -2.512211319115379e+00, -1.968839367271295e+00, -1.405593949009296e+00, -9.276938226011392e-01, -6.860655596159591e-01, -6.031387330013357e-01, -4.914008760589518e-01, -3.430783368694550e-01, -2.010611305694925e-01, -9.569697836285680e-02, -3.442450594169619e-02, -8.100191618084413e-03, -9.872680521800601e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_lda_xc_lda0_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_lda_xc_lda0", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-7.789654317260336e-03, -8.115000780988793e-03, -8.606389220836935e-03, -9.364523874926712e-03, -1.057045685692759e-02, -1.257445254812043e-02, -1.611982719200974e-02, -2.297777093887684e-02, -3.800893433903861e-02, -7.660813958903184e-02, -1.835722109837602e-01, -3.490801547003022e-01, -4.603949162131592e-01, -7.173036384081375e-01, -1.577307218498490e+00, -5.229600259362972e+00, -2.909243233998888e+01, -3.220378208768934e+02, -8.842570341628760e+03, -8.290540164909484e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
