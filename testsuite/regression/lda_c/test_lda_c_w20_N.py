
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_lda_c_w20_N_2_zk():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_w20", 2)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.192723171222683e-01, -1.186805216325116e-01, -1.178307790670568e-01, -1.166116926185273e-01, -1.148649370965517e-01, -1.123668459321346e-01, -1.088044783499452e-01, -1.037479111794962e-01, -9.663433534788436e-02, -8.684045965441833e-02, -7.379111171803547e-02, -5.932465530288091e-02, -5.539159172442759e-02, -5.140607733294067e-02, -4.316649851291059e-02, -3.177048266305813e-02, -1.918340216912187e-02, -8.274936387004831e-03, -1.992653640855575e-03, -3.178481611144518e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_lda_c_w20_N_2_vrho():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_w20", 2)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.289400464041847e-01, -1.289424469536604e-01, -1.283423002357152e-01, -1.283473970304868e-01, -1.274829294296668e-01, -1.274938747362561e-01, -1.262475231518108e-01, -1.262714182714705e-01, -1.244713338591509e-01, -1.245247602798238e-01, -1.219156957740076e-01, -1.220393691309949e-01, -1.182287825442899e-01, -1.185299364118393e-01, -1.128672254597457e-01, -1.136568295885915e-01, -1.048924671596306e-01, -1.071950072820581e-01, -9.233273291118599e-02, -1.000420562484862e-01, -7.157733160090611e-02, -9.919871059018610e-02, -5.219895828320108e-02, -1.135481980383876e-01, -4.876530831159370e-02, -1.110697073531685e-01, -4.568037202303903e-02, -1.007052862914390e-01, -3.879104776569113e-02, -8.841542660600493e-02, -2.926663906600429e-02, -7.264962062911436e-02, -1.882345091997370e-02, -5.215002185667001e-02, -9.164365653261368e-03, -2.788903686351650e-02, -2.437750436157338e-03, -8.209607365761833e-03, -4.096052378296120e-04, -1.159044100913605e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_lda_c_w20_N_2_v2rho2():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_w20", 2)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([4.962028919565300e-04, -6.050308649569731e-04, 4.962274799799844e-04, 5.245696859862099e-04, -6.402378075911177e-04, 5.246251633348908e-04, 5.681453342055679e-04, -6.944126897680909e-04, 5.682753453231086e-04, 6.370203500260593e-04, -7.802601567238869e-04, 6.373421039629353e-04, 7.504039811910614e-04, -9.221452836386302e-04, 7.512651560840517e-04, 9.481636840992578e-04, -1.171199443274830e-03, 9.507430920341384e-04, 1.322319327291849e-03, -1.647584658530377e-03, 1.331398357914226e-03, 2.114065528955581e-03, -2.676904983576948e-03, 2.154318140868528e-03, 4.046925432949033e-03, -5.311949463006919e-03, 4.294136424032428e-03, 9.365559760643643e-03, -1.367278354036942e-02, 1.169823304816850e-02, 1.977206957690242e-02, -4.332832849032386e-02, 5.065528662326634e-02, 1.690265599115389e-02, -9.520698126641233e-02, 2.161438838169191e-01, 2.041621614687353e-02, -1.354131934652817e-01, 3.312180711455667e-01, 3.787586049099097e-02, -2.421481667427179e-01, 5.566495682952270e-01, 8.202270750578478e-02, -6.592511204150702e-01, 1.592575969785526e+00, 1.762553378099652e-01, -2.902909108693942e+00, 8.187770493373423e+00, -6.036720617424244e-01, -2.252609796463535e+01, 8.219668434366034e+01, -4.535189822176667e+01, -3.467770450080994e+02, 1.848272772385883e+03, -2.359743330404334e+03, -1.181912590794121e+04, 1.149142184865017e+05, -3.078017685296985e+05, -1.077096983433002e+06, 2.828658424465373e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
