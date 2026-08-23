
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_lda_c_bj89_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_bj89", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-9.315178814997543e-02, -9.304632239354288e-02, -9.289141536193869e-02, -9.266184497151915e-02, -9.231728797211891e-02, -9.179085561511062e-02, -9.096637283182123e-02, -8.963100082246114e-02, -8.737520974764749e-02, -8.342645465443668e-02, -7.700923945812874e-02, -7.118526708615303e-02, -6.840480916450414e-02, -6.365208017963329e-02, -5.453748125832560e-02, -4.028376454029219e-02, -2.292813058258984e-02, -8.715990728517814e-03, -1.940576647142441e-03, -2.183907481706379e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_lda_c_bj89_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_bj89", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-9.485892447737358e-02, -9.478471074496971e-02, -9.467556997464348e-02, -9.451352616237545e-02, -9.426964931759983e-02, -9.389549086619745e-02, -9.330572846358930e-02, -9.234076748949720e-02, -9.068330264228706e-02, -8.769906443993671e-02, -8.262435869447678e-02, -7.777770089806614e-02, -7.538292513507323e-02, -7.116838150940988e-02, -6.265846918897490e-02, -4.822400296264082e-02, -2.879310906896784e-02, -1.136442195297569e-02, -2.574700776486031e-03, -2.910263779576736e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_lda_c_bj89_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_bj89", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.704363547074962e-06, -7.265476224290730e-06, -8.154445165025150e-06, -9.623486851759725e-06, -1.220241237153312e-05, -1.713916054586558e-05, -2.783325439196680e-05, -5.544602550204711e-05, -1.465182593765823e-04, -5.574544424274816e-04, -2.839747122319685e-03, -9.067822758322451e-03, -1.477665586437248e-02, -3.177084558780523e-02, -1.169061619346993e-01, -7.236027992354063e-01, -7.036804612351938e+00, -1.048658267886409e+02, -2.931123804109307e+03, -2.505705701105066e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
