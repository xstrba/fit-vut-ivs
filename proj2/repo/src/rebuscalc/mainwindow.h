#ifndef MAINWINDOW_H
#define MAINWINDOW_H
/**
 *
 * @file mainwindow.h
 *
 * @brief Graphical User Interface for RebusCalculator.
 * <p>
 *  Reference to functions in abstract groups:
 * </p>
  * @ref Sets_GUI\n
  * @ref Pressed_Mathematical_Button\n
  * @ref Pressed_Special_Button
 * @author
 *          Tibor Kubik <xkubik34>
 * @version 1.3
 * @date 2019/04/02
 *
 * ======== Copyright (c) 2019, Rebus Calc, Inc. , All rights reserved. ============
 */
#include <QMainWindow>

/**
 * @defgroup Sets_GUI
 * Makes Graphical user interface of calculator.
 * @{
 */

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief Sets Main Window of calculator.
     */
    explicit MainWindow(QWidget *parent = 0);
    /**
     * @brief Destroys Main Window of calculator.
     */

    ~MainWindow();
private:
    Ui::MainWindow *ui;
    /**
     * @}
     */
    /**
     * @brief Bool value to check whether we pushed button '='.
     */
    bool lastPressedEquals = false;
    /**
     * @author Tibor Kubik
     * @brief Checks brackets balancation.
     * <p>
     * Additional information: When number of right brackets is greater
     * than number of left brackets, returns -1 and does not write ')'.
     * </p>
     * @param Qstring expr; expression written in calculator.
     * @return 0 if valid, otherwise -1.
     */
    bool areParanthesisBalanced(QString expr);


private slots:
/**
 * @defgroup Pressed_Mathematical_Button
 * Functions to extract data when buttons for digits & mathematic operations are pressed.
 * @{
 */
/**
 * @author Tibor Kubik
 * @ref void MainWindow::on_pushButton_comma_released()
 * @brief Writes '.' on display of calculator.
 * <p>
 * Additional informations: Number of displayed characters has to be
 * lower than 30. Char '.' can not be first. Sets "lastPressedEquals" to false.
 *
 * </p>
*/

    void on_pushButton_comma_released();
    /**
     * @author Tibor Kubik
     * @brief Writes digit on display of calculator.
     * <p>
     * Additional informations: Number of displayed characters has to be
     * lower than 28. Sets "lastPressedEquals" to false.
     * </p>
    */
    void digit_pressed();
    /**
     * @author Tibor Kubik
     * @brief Writes '(' on display of calculator.
     * <p>
     * Additional informations: Number of displayed characters has to be
     * lower than 30.  Sets "lastPressedEquals" to false.
     *
     * </p>
    */
    void on_pushButton_br_left_released();
    /**
     * @author Tibor Kubik
     * @brief Writes ')' on display of calculator.
     * <p>
     * Additional informations:  Number of displayed characters has to be
     * lower than 30. Char ')' can not be first. Number of ')' can not be
     * greater than number of '('. Sets "lastPressedEquals" to false.
     *
     * </p>
    */
    void on_pushButton_br_right_released();
    /**
     * @author Tibor Kubik
     * @brief Writes '!' on display of calculator.
     * <p>
     * Additional informations: Number of displayed characters has to be
     * lower than 30. Char ')' can not be first. Sets "lastPressedEquals" to false.
     *
     * </p>
    */
    void on_pushButton_fact_released();
    /**
     * @author Tibor Kubik
     * @brief Writes '%' on display of calculator.
     * <p>
     * Additional informations: Number of displayed characters has to be
     * lower than 30. Char '%' can not be first. Sets "lastPressedEquals" to false.
     *
     * </p>
    */
    void on_pushButton_mod_released();
    /**
     * @author Tibor Kubik
     * @brief Writes '/' on display of calculator.
     * <p>
     * Additional informations: Number of displayed characters has to be
     * lower than 30. Char '/' can not be first. Sets "lastPressedEquals" to false.
     *
     * </p>
    */
    void on_pushButton_div_released();
    /**
     * @author Tibor Kubik
     * @brief Writes '*' on display of calculator.
     * <p>
     * Additional informations: Number of displayed characters has to be
     * lower than 30. Char '*' can not be first. Sets "lastPressedEquals" to false.
     *
     * </p>
    */
    void on_pushButton_mul_released();
    /**
     * @author Tibor Kubik
     * @brief Writes '+' on display of calculator.
     * <p>
     * Additional informations: Number of displayed characters has to be
     * lower than 30. Char '+' can not be first. Sets "lastPressedEquals" to false.
     *
     * </p>
    */
    void on_pushButton_plus_released();
    /**
     * @author Tibor Kubik
     * @brief Writes '-' on display of calculator.
     * <p>
     * Additional informations: Number of displayed characters has to be
     * lower than 30. Sets "lastPressedEquals" to false.
     *
     * </p>
    */
    void on_pushButton_minus_released();
    /**
     * @author Tibor Kubik
     * @brief Writes "sin(" on display of calculator.
     * <p>
     * Additional informations: Number of displayed characters has to be
     * lower than 28. Sets "lastPressedEquals" to false.
     *
     * </p>
    */
    void on_pushButton_sin_released();
    /**
     * @author Tibor Kubik
     * @brief Writes "cos(" on display of calculator.
     * <p>
     * Additional informations: Number of displayed characters has to be
     * lower than 28. Sets "lastPressedEquals" to false.
     *
     * </p>
    */
    void on_pushButton_cos_released();
    /**
     * @author Tibor Kubik
     * @brief Writes "sqrt(" on display of calculator.
     * <p>
     * Additional informations: Number of displayed characters has to be
     * lower than 27. Sets "lastPressedEquals" to false.
     *
     * </p>
    */
    void on_pushButton_sqrt_released();
    /**
     * @author Tibor Kubik
     * @brief Writes "^" on display of calculator.
     * <p>
     * Additional informations: Number of displayed characters has to be
     * lower than 30. Char '^' can not be first. Sets "lastPressedEquals" to false.
     *
     * </p>
    */
        void on_pushButton_pow_released();
    /**
     * @}
     */
    /**
     * @defgroup Pressed_Special_Button
     * Functions to extract data when buttons 'C', 'DEL', 'ANS' or '=' are pressed.
     * @{
     */
        /**
         * @author Tibor Kubik
         * @brief Deletes last mathematical char on display.
         * <p>
         * Additional informations: When '(' - left bracket is deleted, deletes
         * also sin,cos or sqrt if inserted right before left bracket.
         *  Sets "lastPressedEquals" to false.
         *
         * </p>
        */
    void on_pushButton_del_released();
    /**
     * @author Tibor Kubik
     * @brief Clears display.
     * <p>
     * Additional informations: Sets "lastPressedEquals" to false.
     *
     * </p>
    */
    void on_pushButton_C_released();
    /**
     * @author Tibor Kubik
     * @brief Writes last result as an input.
     * <p>
     * Additional informations: When "error" is last result
     *  or "lastPressedEquals" is false does not write anything.
     *</p>
    */
    void on_pushButton_ans_released();
    /**
     * @author Tibor Kubik
     * @brief Display result of expression.
     * <p>
     * Additional informations: When expression has invalid input or
     * any mathematical errors occurs; display "error". Sets last
     * "lastPressedEquals" to true.
     *
     * </p>
    */
    void on_pushButton_equals_released();
    /**
     * @author Tibor Kubik
     * @brief Switch calculator to light/dark mode.
     * @param bool checked; Ligth mode when true; dark mode when false.
    */
    void on_checkBox_toggled(bool checked);
    /**
     * @}
     */
};

#endif // MAINWINDOW_H
/** End of file mainwindow.h **/
