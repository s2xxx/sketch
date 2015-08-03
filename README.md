# sketch

/*!
   @file       ${file_name}
   @author     s2xxx (slava@s2xxx.ru)
   @version    0.1
   @date       ${date}
   @bug        No known bugs.
   @copyright  GNU Public License.
   @brief      ${todo}
      
*/


${filecomment}

/* Includes -----------------------------------------------------------------*/
#include "${file_base}.h"
${includes}
/* Defines ------------------------------------------------------------------*/
	/*!<  */
/* Enum, struct, union ------------------------------------------------------*/
/* Typedefs -----------------------------------------------------------------*/
	/*!<  */
/* Variables ----------------------------------------------------------------*/
	/*!<  */
/* Function prototype -------------------------------------------------------*/

${declarations}



${filecomment}
#ifndef ${include_guard_symbol}
#define ${include_guard_symbol}

/* Includes -----------------------------------------------------------------*/
${includes}
/* Defines ------------------------------------------------------------------*/
	/*!<  */
/* Enum, struct, union ------------------------------------------------------*/
/* Typedefs -----------------------------------------------------------------*/
	/*!<  */
/* Variables ----------------------------------------------------------------*/
	/*!<  */

${declarations}

#endif /* ${include_guard_symbol} */











create_global_function
/*!
   @brief   TODO

   @param   ${param_a}
   @return  ${ret_val}
   @note    
 */
void ${name}(${param_a})
{
	${cursor}
	return ${ret_val};
}

create_static_function
/*!
   @brief   TODO
   @note
   @static    
 */
static void ${name}(void)
{
	${cursor}
	return;
}