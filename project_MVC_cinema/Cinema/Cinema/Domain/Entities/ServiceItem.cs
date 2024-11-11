using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Blog.Domain.Entities
{
    public class ServiceItem : EntityBase
    {
        [Required(ErrorMessage ="Заполните название")]
        [Display(Name = "Название")]
        public override string Title { get; set; }

        [Display(Name = "Краткое описание")]
        public override string Subtitle { get; set; }

        [Display(Name = "Полное описание")]
        public override string Text { get; set; }
        
    }
}
