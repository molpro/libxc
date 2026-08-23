
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_k_pg1_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_pg1", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.020958381641187e+02, 9.846801544085019e+01, 9.351121325038918e+01, 8.688996049838443e+01, 7.832878170277283e+01, 6.776755702139607e+01, 5.559681839527070e+01, 4.290021899495316e+01, 3.143599346689713e+01, 2.240432101224240e+01, 1.169687885422371e+01, 2.533728521487621e+00, 1.720661680963785e+00, 1.316965915523882e+00, 9.274172906865112e-01, 7.588882431959892e-01, 7.041205877925156e-01, 6.463256685725453e-01, 6.027861181680759e-01, 5.742321716888192e-01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_k_pg1_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_pg1", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.383535529812347e+02, 1.321590808617805e+02, 1.236769620464861e+02, 1.123062855744744e+02, 9.751465100363777e+01, 7.906648136267498e+01, 5.735601356969627e+01, 3.373875580052241e+01, 1.077299262560092e+01, -6.436305010525774e+00, -6.414102061619619e+00, 2.858227691168094e+00, 2.486689309408713e+00, 1.288783866134885e+00, 2.944455847983417e-02, -6.839791918458822e-01, -7.041201783780126e-01, -6.463256685725453e-01, -6.027861181680759e-01, -5.742321716888192e-01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_pg1_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_pg1", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.412741745757393e-04, 3.652231217174988e-04, 4.027181524057582e-04, 4.636670684994645e-04, 5.682825195664210e-04, 7.626314094187478e-04, 1.167731459993564e-03, 2.164819162050828e-03, 5.251406379701729e-03, 1.761608871247019e-02, 6.900703344131143e-02, 1.095040743413390e-01, 1.415756796363316e-01, 3.366607536722368e-01, 1.428704036924788e+00, 1.043535489506060e+01, 1.272848166781701e+02, 3.883781956864946e+03, 4.376504016110850e+05, 3.237673133752216e+08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_pg1_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_pg1", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([7.720610644880769e-01, 7.997865571822900e-01, 8.423016146616615e-01, 9.094843129994354e-01, 1.020555500611508e+00, 1.217208228161505e+00, 1.603308055692766e+00, 2.483177455952073e+00, 4.878661735256867e+00, 1.180477735779476e+01, 2.261544120930717e+01, 6.624007647670758e+00, 5.287497065409764e+00, 1.115069892416972e+01, 4.028764561022485e+01, 1.677968074974687e+02, 1.433997427903267e+03, 4.016300751777158e+04, 4.220953387229526e+06, 2.974681719700928e+09]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_pg1_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_pg1", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.757852580245196e-06, -3.163154632047670e-06, -3.853003736831372e-06, -5.117579042578655e-06, -7.697493100487206e-06, -1.383850424628969e-05, -3.207544315298395e-05, -1.060714091458015e-04, -5.614978455041166e-04, -5.043238570215122e-03, -6.732412649531325e-02, -2.846492442408727e-01, -4.664876525956174e-01, -2.648272406079248e+00, -3.768540444462046e+01, -1.108260334882885e+03, -1.296124746800185e+05, -1.206700983077577e+08, -1.532302992242752e+12, -8.386021856816717e+17]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_pg1_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_pg1", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([9.144110924456758e-12, 1.137283724291245e-11, 1.555170165379582e-11, 2.435104847424802e-11, 4.623612031183231e-11, 1.153034721657431e-10, 4.209779314081703e-10, 2.588568549310865e-09, 3.131629416724827e-08, 8.268611565838802e-07, 6.491149295610164e-05, 8.653381877694480e-03, 4.538656824037054e-02, 3.983051063327576e-01, 1.541629523230973e+01, 1.134409967537554e+03, 7.129686358530945e+01, 6.200586513229276e-45, 0.000000000000000e+00, 0.000000000000000e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
