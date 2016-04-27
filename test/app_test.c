#include <ctest.h>
#include <app.h>

CTEST(app_suite, nuli)
{
    const double a = 0, b = 0, c = 0;
    double d, x1, x2;

    const double koren = uravn(a, b, c, &d, &x1, &x2), ex_koren = -1;

    ASSERT_EQUAL(ex_koren, koren);
}

CTEST(app_suite, discriminant_menshe_nulya)
{
    const double a = 4, b = 0, c = 3;
    double d, x1, x2;

    const double koren = uravn(a, b, c, &d, &x1, &x2), ex_koren = 0, ex_d = -48;

    ASSERT_EQUAL(ex_koren, koren);
    ASSERT_DBL_NEAR(ex_d, d);
}

CTEST(app_suite, odin_koren)
{
    const double a = 1, b = -2, c = 1;
    double d, x1, x2;

    const double koren = uravn(a, b, c, &d, &x1, &x2), ex_koren = 1, ex_d = 0, ex_x1 = 1;

    ASSERT_EQUAL(ex_koren, koren);
    ASSERT_DBL_NEAR(ex_d, d);
    ASSERT_DBL_NEAR(ex_x1, x1);
}

CTEST(app_suite, dva_kornya)
{
    const double a = 2, b = -3, c = 1;
    double d, x1, x2;
    
    const double koren = uravn(a, b, c, &d, &x1, &x2), ex_koren = 2, ex_d = 1, ex_x1 = 1, ex_x2 = 0.5;

    ASSERT_EQUAL(ex_koren, koren);
    ASSERT_DBL_NEAR(ex_d, d);
    ASSERT_DBL_NEAR(ex_x1, x1);
    ASSERT_DBL_NEAR(ex_x2, x2);
}