
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_lda_c_ow_N_2_zk():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_ow", 2)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.953309847892110e-02, -4.947362791847662e-02, -4.938629285111383e-02, -4.925689520978296e-02, -4.906275538465312e-02, -4.876629300489947e-02, -4.830230284048498e-02, -4.755116047917796e-02, -4.627801347117434e-02, -4.395420622368756e-02, -3.850735833567318e-02, -2.678551656915392e-02, -2.439245472949892e-02, -2.324416534145470e-02, -1.877756938811670e-02, -1.180001327467969e-02, -4.837418026467041e-03, -9.896941313581140e-04, -7.628223744402011e-05, -1.866535418511751e-06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_lda_c_ow_N_2_vrho():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_ow", 2)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.049458679314470e-02, -5.049699846661575e-02, -5.045124139193762e-02, -5.045638171978534e-02, -5.038652917362676e-02, -5.039762970865600e-02, -5.028822427208719e-02, -5.031265314375642e-02, -5.013492719276690e-02, -5.019017804784079e-02, -4.988608466952670e-02, -5.001610158850141e-02, -4.945599468309397e-02, -4.978010659088246e-02, -4.863505871726941e-02, -4.951352403447155e-02, -4.680743129629684e-02, -4.948985805437973e-02, -4.181546851684632e-02, -5.135347454222775e-02, -2.740621875781175e-02, -6.357021552800700e-02, -1.079233175598587e-02, -9.010378081859817e-02, -9.387870202902831e-03, -9.021549461644549e-02, -9.646934351225326e-03, -8.241827829863674e-02, -7.886093516911488e-03, -7.350602707912965e-02, -4.836739107847766e-03, -5.917063993513047e-02, -1.899301725526076e-03, -3.757605883799280e-02, -3.654031613303087e-04, -1.583468039826835e-02, -2.651129530805129e-05, -3.767526856106072e-03, -6.289045706825172e-07, -4.349470598253585e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_lda_c_ow_N_2_v2rho2():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_ow", 2)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([5.493687028729611e-04, -5.569672481576396e-04, 5.493951124500680e-04, 5.832525372468267e-04, -5.915019508635036e-04, 5.833123583624809e-04, 6.355823689187895e-04, -6.448769307954948e-04, 6.357233501041033e-04, 7.189338132330479e-04, -7.299934855439903e-04, 7.192855404536735e-04, 8.576803652973649e-04, -8.719530978755731e-04, 8.586326893590864e-04, 1.103578918173479e-03, -1.124398046599705e-03, 1.106478677005297e-03, 1.579659340818612e-03, -1.616309534125208e-03, 1.590106928565664e-03, 2.621094703826208e-03, -2.707466094478943e-03, 2.668953362038005e-03, 5.288019027957336e-03, -5.604446120102178e-03, 5.595282767834928e-03, 1.315339026265985e-02, -1.522951969720594e-02, 1.621484424549584e-02, 3.028395867247616e-02, -4.982505286450240e-02, 7.185883265224365e-02, 2.868482756934113e-02, -9.668909973448594e-02, 2.600033578656522e-01, 3.659078520495559e-02, -1.360181165578920e-01, 3.878852506662998e-01, 7.031673121355890e-02, -2.527848703720356e-01, 6.679958720937382e-01, 1.703613514306729e-01, -6.901184587057483e-01, 1.827444817820391e+00, 5.264640312302823e-01, -2.865317913025206e+00, 7.974675166908806e+00, 2.012525179457902e+00, -1.857649351898466e+01, 5.581980715232893e+01, 9.507229827856092e+00, -2.027404949133644e+02, 6.771181389727230e+02, 6.665614755521142e+01, -4.763548690987192e+03, 1.769245113193180e+04, 1.102078913060337e+03, -3.828093009787016e+05, 1.502589123960546e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
