using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Blog.Domain.Entities
{
    public abstract class EntityBase
    {
        protected EntityBase() => DateAdded = DateTime.UtcNow;

        [Required]
        public Guid Id                          { get; set; }
        
        [Display (Name = "название(заголовки)")]
        public virtual string Title             { get; set; }

        [Display(Name = "краткое описание")]
        public virtual string Subtitle          { get; set; }

        [Display(Name = "полное описание")]
        public virtual string Text              { get; set; }

        [Display(Name = "титульная картинка")]
        public virtual string TitleImagePath  { get; set; }

        [Display(Name = "метатег title")]
        public string MetaTitle                 { get; set; }

        [Display(Name = "метатег description")]
        public string MetaDescription          { get; set; }

        [Display(Name = "метатег keywords")]
        public string MetaKeywords              { get; set; }

        [DataType(DataType.Time)]
        public DateTime DateAdded               { get; set; }

    }
}
