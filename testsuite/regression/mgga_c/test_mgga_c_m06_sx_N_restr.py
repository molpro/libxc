
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_c_m06_sx_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_m06_sx", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-8.530931322483358e-02, -8.466262188083935e-02, -8.372610205784958e-02, -8.236536843343185e-02, -8.037796552153602e-02, -7.745046524473731e-02, -7.307362201524108e-02, -6.634189067012536e-02, -5.537794324299081e-02, -3.642222345163332e-02, -2.262529553355925e-02, -7.915796885531207e-02, -5.754974738779740e-02, -3.693631583492994e-02, -2.344337296931065e-02, -9.575856392022245e-04, 3.187161701936247e-02, 2.488926249114935e-02, 7.036085131901395e-03, 8.768409782831678e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_c_m06_sx_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_m06_sx", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.087062991724657e-01, -1.073981754243646e-01, -1.054785108542401e-01, -1.026445625182435e-01, -9.844012711483527e-02, -9.221366997719890e-02, -8.323034872684573e-02, -7.160694621302138e-02, -6.233972625710493e-02, -7.289527838053270e-02, -1.069290482095925e-01, -8.547892544346600e-02, -7.987810962223839e-02, -7.056458935512280e-02, -4.490503241058870e-02, -5.640805229661671e-02, -3.371765499547462e-03, 3.202431705443866e-02, 1.079269679141607e-02, 1.412808997507661e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_m06_sx_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_m06_sx", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.969336004617658e-07, 1.830131997466101e-07, 1.570271612811056e-07, 1.051440962195618e-07, -6.793316951102703e-09, -2.703314743449804e-07, -9.503479367546934e-07, -2.832923449787799e-06, -7.677504412761962e-06, -7.539076746784339e-06, 2.802696257704326e-04, 7.416042698184177e-03, 1.335360475616819e-02, 1.128697523454873e-02, 5.802253966254619e-05, 1.845217168798347e-01, 1.680336483121047e+00, -2.214286400799542e+01, -1.220522548957885e+03, -1.417553283050374e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_m06_sx_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_m06_sx", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.421441317300690e-05, -2.588937604237658e-06, 5.918364812947020e-05, 1.517541000556038e-04, 2.917619301637978e-04, 5.039570307860951e-04, 8.179493156158442e-04, 1.235923391490094e-03, 1.603144436719205e-03, 1.350046399976960e-03, -7.353617169019435e-04, -8.331639299145868e-03, -8.247599123399655e-03, -8.630921849875343e-04, 1.124886846194291e-02, 1.421915623799425e-02, 1.299330150237365e-02, 7.866630364205089e-03, 2.729933225684782e-03, 4.302891065832445e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_m06_sx_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_m06_sx", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-7.984523505401229e-04, -8.765564829542901e-04, -9.997188374601649e-04, -1.200886697208076e-03, -1.544470654335422e-03, -2.161835814910891e-03, -3.316447230863077e-03, -5.394600754174245e-03, -7.549576123181034e-03, 1.503569361343132e-03, 4.647616824944089e-02, 7.444094374724743e-02, 6.927841205572030e-02, -2.940366507879502e-01, -4.409531884657960e-01, 7.688911806866581e-01, -1.370923070401760e+02, -2.845323054075932e+02, 1.176284358412893e+04, 1.373355029692435e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_m06_sx_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_m06_sx", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.594885236412934e-08, 1.867441559084260e-08, 2.336524671617120e-08, 3.206257103043710e-08, 4.992724604951307e-08, 9.201130956173216e-08, 2.100294499914824e-07, 6.136020312188820e-07, 2.224772507223756e-06, 8.259934315645108e-06, 9.475867895695956e-05, -9.861125892123668e-03, -4.580650121076012e-02, 1.803213353413257e-01, 1.330080064112914e+00, 2.227736188777785e+01, 1.065953724078095e+04, 1.140530366277660e+06, -9.191283941373471e+08, -1.130885431505415e+14]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_m06_sx_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_m06_sx", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.792746154160252e-05, -1.971343648424072e-05, -2.254214256177943e-05, -2.719479272239703e-05, -3.523489864367156e-05, -4.999721726823409e-05, -7.894117865568621e-05, -1.388073925775979e-04, -2.664354220829580e-04, -6.080293978145186e-04, -2.807894637019847e-03, 2.852679207676090e-03, 1.248761638378537e-02, -1.357750538227056e-01, -6.578921259055071e-01, -3.899692673728210e+00, -1.659408686255507e+01, 1.441543875899475e+01, 2.529318449404261e+03, 3.438604143774507e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_m06_sx_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_m06_sx", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.885667253413974e-13, -3.602132244072795e-13, -4.943057677490447e-13, -7.751521774292741e-13, -1.464382821218025e-12, -3.573853406428101e-12, -1.231304830711604e-11, -6.671964006288347e-11, -6.553363420439943e-10, -1.633090565282170e-08, -2.666041409304780e-06, -1.276700333246173e-03, -4.307681650807760e-03, -1.737408695979072e-01, -4.457235121084968e+00, -8.622138400520956e+02, -1.392270342433044e+06, -4.756789489685732e+09, -1.050428381723261e+14, -7.592674007163842e+19]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_m06_sx_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_m06_sx", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.247012556875081e-10, 2.719574567036591e-10, 3.558032643946628e-10, 5.180714557103455e-10, 8.721967654555773e-10, 1.782512618169306e-09, 4.695902591235402e-09, 1.712874661834180e-08, 9.442130502043502e-08, 8.985074712027866e-07, 1.996056984343756e-05, 6.342956942172917e-04, 2.941641096775777e-03, 1.205698066455379e-01, 2.108809037572520e+00, 7.841873069267940e+01, 5.699640641486229e+03, 1.717123997101825e+06, 6.989108327540143e+09, 6.284419297589544e+14]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_m06_sx_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_m06_sx", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-7.021637784295597e-08, -9.972203878602098e-08, -1.498860550123319e-07, -2.407255782753445e-07, -4.193889800490042e-07, -8.097292780554805e-07, -1.779161649910635e-06, -4.562502117052643e-06, -1.373519531449634e-05, -4.592542168425608e-05, -1.393550454362110e-04, -2.979421861901303e-04, -3.837487976431272e-03, -1.091673692969174e-01, -1.035175339721361e+00, -7.754242622746714e+00, -5.688852921746604e+01, -7.705675063712426e+02, -3.074418502826085e+04, -3.814489934664812e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
