
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_lda_c_br78_N_2_zk():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_br78", 2)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-7.345840947266412e-02, -7.303773537538678e-02, -7.242682282101245e-02, -7.153638812507158e-02, -7.023238421392769e-02, -6.831179318121851e-02, -6.546618712098692e-02, -6.123427848753987e-02, -5.497454795907893e-02, -4.599676554000070e-02, -3.379983466548048e-02, -2.053046035137643e-02, -1.763479880741152e-02, -1.532461590107742e-02, -1.060447629270158e-02, -5.457903270910874e-03, -1.839963134316568e-03, -3.294445711848476e-04, -2.398341114648643e-05, -5.787251983064956e-07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_lda_c_br78_N_2_vrho():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_br78", 2)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-8.029738670098685e-02, -8.030096325288427e-02, -7.993600265113841e-02, -7.994359129827995e-02, -7.940769977446363e-02, -7.942397911914344e-02, -7.863003632089821e-02, -7.866551466840153e-02, -7.747408146111225e-02, -7.755317199019639e-02, -7.573192245933470e-02, -7.591405007929071e-02, -7.305430029269992e-02, -7.349358309197955e-02, -6.882111850481398e-02, -6.995236723424837e-02, -6.184455488625442e-02, -6.503106155320108e-02, -4.966970040058938e-02, -5.965093916158314e-02, -2.880447573965692e-02, -6.054742473710081e-02, -1.120717542907877e-02, -7.199751173587662e-02, -9.295251100502088e-03, -6.773048898125837e-02, -8.488107088934917e-03, -5.646543293467693e-02, -5.800758908312043e-03, -4.285907116408090e-02, -2.782486839502149e-03, -2.791374458841541e-02, -8.316925478849655e-04, -1.440172463519819e-02, -1.292309189484782e-04, -5.278568723820765e-03, -8.459287253130978e-06, -1.184648100092625e-03, -1.953312363908928e-07, -1.348570462164816e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_lda_c_br78_N_2_v2rho2():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_br78", 2)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([7.877692749414095e-04, -8.529468259292852e-04, 7.878054974894704e-04, 8.320644891886701e-04, -9.022246160228641e-04, 8.321460736141305e-04, 8.999304087369455e-04, -9.779184890244684e-04, 9.001210950318959e-04, 1.006772624048211e-03, -1.097542529659161e-03, 1.007242618888061e-03, 1.181581516721526e-03, -1.294411947233329e-03, 1.182831437288370e-03, 1.483529134274453e-03, -1.637597929232622e-03, 1.487234505457184e-03, 2.045860014061172e-03, -2.286443742269707e-03, 2.058680530419809e-03, 3.204869013138882e-03, -3.660234083370476e-03, 3.260062282966759e-03, 5.910660689269069e-03, -7.050291777388802e-03, 6.232500667555181e-03, 1.282772670379692e-02, -1.709174177166185e-02, 1.559624708220286e-02, 2.503253316948155e-02, -4.805905218189985e-02, 5.597308250039474e-02, 2.221328473368745e-02, -8.791538040591829e-02, 1.714483544405050e-01, 2.685749532085881e-02, -1.181453781148198e-01, 2.404031075353877e-01, 4.615786717655941e-02, -1.980506158026296e-01, 3.778184935386502e-01, 9.482691300365861e-02, -4.613884863414613e-01, 8.901178799913354e-01, 2.392691441323111e-01, -1.545243672304533e+00, 3.252918432656123e+00, 7.555173495097428e-01, -7.896371452726788e+00, 1.958041107040441e+01, 3.150041790080318e+00, -7.119149232962504e+01, 2.180020290859558e+02, 2.094546209833833e+01, -1.518986740430402e+03, 5.519962418553727e+03, 3.416969416976770e+02, -1.188945796069364e+05, 4.654758120033667e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
